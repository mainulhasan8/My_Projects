#include<iostream>
using namespace std;

class Product
{
public:

    string productname,originName;
    int quantity;
    double price;

    Product(string a,string b,double c,int d)
    {
        productname = a;
        originName = b;
        price = c;
        quantity = d;
    }

    void showProductStore()
    {
        cout<<"Product Title : "<<productname<<endl;
        cout<<"Origin Name : "<<originName<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Quantity : "<<quantity<<endl;
    }
};

class Productdetails : public Product
{
private:
    string category;

public:

    Productdetails(string ct,string a,string b,double c,int d):Product(a,b,c,d)
    {
        category = ct;
    }

    void showDetail()
    {
        cout<<"Product Description : "<<endl<<endl;
        cout<<"Product Category : "<<category<<endl;
        showProductStore();
        cout<<endl;
    }
};

class Customer
{
public:
    string name,type, gender;

    Customer(string a,string b, string c)
    {
        name=a;
        type=b;
        gender=c;
    }

    friend void buyProducts( Productdetails a, Customer b);
};

void buyProducts( Productdetails a, Customer b)
{
    double discount;

    if((b.type.compare("Regular")) == 0)
    {
            discount=(a.price*18)/100;
            a.price=a.price-discount;

            if (b.gender.compare("C")==0)
            cout<<"Child "<<b.name<<" is a "<<b.type<<" Customer, will get 18% discount,so Discount price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("M")==0)
            cout<<"Mr. "<<b.name<<" is a "<<b.type<<" Customer, will get 18% discount,so Discount price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("F")==0)
            cout<<"Mrs. "<<b.name<<" is a "<<b.type<<" Customer, will get 18% discount,so Discount price:"<<a.price<<" taka."<<endl<<endl;
    }

    else{
            if (b.gender.compare("C")==0)
            cout<<"Child "<<b.name<<" is a "<<b.type<<" Customer, will  not get 18% discount,so price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("M")==0)
            cout<<"Mr. "<<b.name<<" is a "<<b.type<<" Customer, will  not get 18% discount,so price:"<<a.price<<" taka."<<endl<<endl;

            if (b.gender.compare("F")==0)
            cout<<"Mrs. "<<b.name<<" is a "<<b.type<<" Customer, will  not get 18% discount,so price:"<<a.price<<" taka."<<endl<<endl;
    }
}

int main()
{
    Productdetails A("Cosmatic","White","London",3000,5);
    Customer cs("Mainul","Regular","M");
    A.showDetail();
    buyProducts(A,cs);

    Productdetails B("Stationary","Linc pen","India",30,3500);
    Customer ds("Arpi","Non_Regular","F");
    B.showDetail();
    buyProducts(B,ds);

    Productdetails C("Garments","Pant","Italy",6000,28);
    Customer es("Mehedi","Regular", "C");
    C.showDetail();
    buyProducts(C,es);
}
