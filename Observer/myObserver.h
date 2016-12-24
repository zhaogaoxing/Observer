#pragma once
#ifndef _OBESRVER_H_
#define _OBESRVER_H_

#include <string>
#include <list>
using namespace std;

class Subject;

class myObserver
{
public:
	~myObserver();
	virtual void Update(Subject*) = 0;
protected:
	myObserver();
private:
};

class ConcreteObserverA :public myObserver
{
public :
	ConcreteObserverA();
	~ConcreteObserverA();
	virtual void Update(Subject*);
protected:
private:
	string m_state;
};

class ConcreteObserverB :public myObserver
{
public :
	ConcreteObserverB();
	~ConcreteObserverB();
	virtual void Update(Subject*);
protected:
private:
	string m_state;
};

class Subject
{
public:
	~Subject();
	virtual void Notify();
	virtual void Attach(myObserver*);
	virtual void Detach(myObserver*);
	virtual string GetState();
	virtual void SetState(string state);
protected:
	Subject();
private:
	string m_state;
	list<myObserver*>m_list;
};

class ConcreteSubjectA :public Subject
{
public:
	ConcreteSubjectA();
	~ConcreteSubjectA();
protected:
private:
};

class ConcreteSubjectB :public Subject
{
public:
	ConcreteSubjectB();
	~ConcreteSubjectB();
protected:
private:
};

#endif