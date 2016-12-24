#include "stdafx.h"
#include "myObserver.h"
#include <algorithm>
#include <iostream>

using namespace std;

myObserver::myObserver()
{
}

myObserver::~myObserver()
{
}

ConcreteObserverA::ConcreteObserverA()
{

}
ConcreteObserverA::~ConcreteObserverA()
{

}

void ConcreteObserverA::Update(Subject* pSubject)
{
	this->m_state = pSubject->GetState();
	cout << "The ConcreteObserverA is " << m_state << std::endl;
}

ConcreteObserverB::ConcreteObserverB()
{

}
ConcreteObserverB::~ConcreteObserverB()
{

}

void ConcreteObserverB::Update(Subject* pSubject)
{
	this->m_state = pSubject->GetState();
	cout << "The ConcreteObserverB is " << m_state << std::endl;
}

Subject::Subject()
{

}
Subject::~Subject()
{

}
void Subject::Attach(myObserver* pmyObserver)
{
	this->m_list.push_back(pmyObserver);
	cout << "Attach an Observer\n";
}
void Subject::Detach(myObserver* pmyObserver)
{
	list<myObserver*>::iterator iter;
	iter = find(m_list.begin(),m_list.end(),pmyObserver);
	if (iter != m_list.end())
	{
		m_list.erase(iter);
	}
	cout << "Detach an Observer\n ";
}
void Subject::Notify()
{
	list<myObserver*>::iterator iter = this->m_list.begin();
	for (; iter != m_list.end();iter++)
	{
		(*iter)->Update(this);
	}
}

string Subject::GetState()
{
	return this->m_state;
}
void Subject::SetState(string state)
{
	this->m_state = state;
}
ConcreteSubjectA::ConcreteSubjectA()
{

}
ConcreteSubjectA::~ConcreteSubjectA()
{

}
ConcreteSubjectB::ConcreteSubjectB()
{

}
ConcreteSubjectB::~ConcreteSubjectB()
{

}
