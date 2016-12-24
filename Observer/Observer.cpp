// Observer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "myObserver.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	myObserver* p1 = new ConcreteObserverA();
	myObserver* p2 = new ConcreteObserverB();
	myObserver* p3 = new ConcreteObserverA();

	Subject* pSubject = new ConcreteSubjectA();
	pSubject->Attach(p1);
	pSubject->Attach(p2);
	pSubject->Attach(p3);

	pSubject->SetState("old");

	pSubject->Notify();

	cout << "-------------" << endl;
	pSubject->SetState("new");

	pSubject->Detach(p3);
	pSubject->Notify();

	system("pause");

	return 0;
}

