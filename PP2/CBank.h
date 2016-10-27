#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "CBankClient.h"

enum class idPrimitive
{
		CriticalSection = 0
	,	Mutex
	,	Semaphore
	,	Event
};

class CBankClient;

class CBank
{
public:
	CBank();
//////////////////////////////////////////////////////////////////////
// Methods
public:
	CBankClient *					CreateClient();
	void							UpdateClientBalance(size_t index, int value);
	void							UpdateClientBalance(CBankClient& client, int value);

	void							CreateThreads(size_t amountCpu);
	void							ResumeThreads();
private:
	int								GetTotalBalance();
	void							SetTotalBalance(int value);
	void							SomeLongOperations();
	unsigned int					GetSleepDuration();
	static int						GetAffinityMask(size_t amountThread, size_t threadIndex);

//////////////////////////////////////////////////////////////////////
// Data
private:
	std::vector<CBankClient>		m_clients;
	std::vector<HANDLE>				m_threads;
	int								m_totalBalance;

	
};