#include<iostream>
using namespace std;

//class Person 
//{ 
//public: 
//	virtual void BuyTicket() 
//	{ 
//		cout << "买票-全价" << endl;
//	} 
//}; 
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() 
//	{ 
//		cout << "买票-半价" << endl; 
//	}
//};
//void Func(Person& p)
//{ 
//	p.BuyTicket(); 
//} 
//int main()
//{ 
//	Person ps;
//	Student st; 
//	Func(ps); 
//	Func(st);  
//	return 0; 
//}


//class A{}; 
//
//class B : public A {}; 
//
//class Person
//{
//public: 
//	virtual A* f() 
//	{ 
//		return new A; 
//	} 
//}; 
//class Student : public Person 
//{ 
//public: 
//	virtual B* f() 
//	{ 
//		return new B; 
//	} 
//};


//class Person 
//{ 
//public: 
//	 ~Person() 
//	{ 
//		cout << "~Person()" << endl;
//	} 
//};
//
//class Student : public Person 
//{ 
//public: 
//	 ~Student() 
//	{ 
//		cout << "~Student()" << endl; 
//	} 
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，
////才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{ 
//	Person* p1 = new Person; 
//	Person* p2 = new Student;  
//
//	delete p1; 
//	delete p2;  
//	return 0;
//}







//class Car 
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};















//class Car
//{
//public:
//	void Drive()
//	{}
//};
//class Benz :public Car 
//{
//public:
//	virtual void Drive() override 
//	{
//		cout << "Benz-舒适" << endl; 
//	}
//};



//
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BWM :public Car 
//{
//public:
//	virtual void Drive() override
//	{
//		cout << "BWM-操控" << endl;
//	}
//};
//
//void Test()
//{
//	//Car c;抽象类实例化不出对象
//	Benz bz;
//	BWM bw;
//	Car* p;
//	p = &bz;
//	p->Drive();
//
//	p = &bw;
//	p->Drive();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}	
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}

//int main()
//{
//	cout << sizeof(Base) << endl;
//
//	Base b1;
//	Base b2;
//



















//
//
//	//虚表存放在什么地方呢？
//	printf("虚表指针：%p\n", *((int*)&b1));
//
//	int a = 0;//临时变量---栈
//	static int b = 0;//全局变量、静态变量---数据段
//	int* p = new int;//动态开辟---堆
//	const char* str = "hello world";//只读常量---代码段
//
//	printf("栈：%p\n", &a);
//	printf("数据段(静态区):%p\n", &b);
//	printf("堆:%p\n", p);
//	printf("代码段(常量区):%p\n", str);
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Person& p) {
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}

//
//class Base {
//public: 
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1 = 1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2 = 2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1 = 3;
};

//如何将这个虚表打印出来呢？

typedef void(*VFUNC)();
void PrintVFT(VFUNC* vftable)//VFUNC vftable[]但是最终都会退化成为数组的首元素地址
{
	printf("虚表指针：%p\n", vftable);
	for (int i = 0; vftable[i] != nullptr; ++i)
	{
		printf("vftable[%d]:%p->", i, vftable[i]);
		VFUNC f = vftable[i];
		f();
	}
}

int main()
{
	//Base1 b1;
	//Base2 b2;
	Derive d;


	printf("func1:%p\n", &Derive::func1);

	//Base1* p1 = &d;
	//Base2* p2 = &d;
	/*p1->func1();
	p2->func1();*/
	PrintVFT((VFUNC*)(*((int*)&d)));

	cout << endl;
	PrintVFT((VFUNC*)(*(int*)((char*)&d + sizeof(Base1))));

	return 0;
}