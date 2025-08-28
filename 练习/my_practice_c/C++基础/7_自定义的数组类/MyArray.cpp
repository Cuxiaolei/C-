#include "MyArray.h"

MyArray::MyArray()
{
	cout << "MyArray()..." << endl;
	this->len = 0;
	this->space = NULL;
}
MyArray::MyArray(int len)
{
	if (len <= 0)
	{
		this->len = 0;
		return;
	}
	else
	{
		this->len = len;
		//��space���ٿռ�
		this->space = new int[this->len];
		cout << "MyArray::MyArray(int len)..." << endl;
		return;
	}
}
MyArray::MyArray(const MyArray& another)
{
	if (another.len >= 0)
	{
		this->len = another.len;

		//���
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}
		cout << "MyArray::Myarray(const MyArray& another)..." << endl;
	}
}
MyArray::~MyArray()
{
	if (this->space != NULL)
	{
		delete[]this->space;
		this->space = NULL;
		len = 0;
		cout << "Myarray::~MyArray()..." << endl;
	}
}

void MyArray::setData(int index, int data)
{
	if (this->space != NULL)
	{
		this->space[index] = data;
	}
}
int MyArray::getData(int index)
{
	return this->space[index];
}
int MyArray::getLen() const
{
	return this->len;
}
void MyArray::printMyarray()
{
	for (int i = 0; i < this->len; i++)
	{
		cout << this->space[i] << "  ";
	}
	cout << endl;
}


//�Ⱥŵ�����
MyArray& MyArray::operator=(const MyArray& another)
{
	if (this == &another)
	{
		return *this;
	}

	if (this->space != NULL)
	{
		delete[]this->space;
		this->space = NULL;
		this->len = 0;
	}

	this->len = another.len;

	//���
	this->space = new int[this->len];
	for (int i = 0; i < this->len; i++)
	{
		this->space[i] = another.space[i];
	}
	cout << "MyArray& MyArray::operator=(const MyArray& another)..." << endl;

	return *this;
}
//�����ŵ�����
int& MyArray::operator[](int index) const
{
	return this->space[index];
}
//<<������
ostream& operator<<(ostream& os,const MyArray& arr)
{
	for (int i = 0; i < arr.getLen(); i++)
	{
		os << arr[i] << "  ";
	}
	os << endl;

	return os;
}

istream& operator>>(istream& is, const MyArray& arr)
{
	cout << "������" << arr.getLen() << "������";
	for (int i = 0; i < arr.getLen(); i++)
	{
		is >> arr[i];
	}


	return is;
}

//==������
bool operator==(MyArray& arr1, MyArray& arr2)
{
	if (arr1.getLen() != arr2.getLen())
	{
		return false;
	}
	for (int i = 0; i < arr1.getLen(); i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}

	return true;
}

