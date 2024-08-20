#include<bits/stdc++.h>

using namespace std;

class Box {
private:
    int length;
    int height;
    int width;

public:
    Box() : length(0), height(0), width(0) {}

    Box(int l, int h, int w) : length(l), height(h), width(w) {}

    int getLength() const {
        return length;
    }

    int getHeight() const {
        return height;
    }

    int getWidth() const {
        return width;
    }

    long long CalculateVolume() const {
        return static_cast<long long>(length) * height * width;
    }

    bool operator<(const Box& b) const {
        if(length < b.length){
            return true;
        }
        else if (length == b.length && width < b.width){
            return true;
        }
        else if(length == b.length && width == b.width && height < b.height){
            return true;
        }
        else{
            return false;
        }
    }
    
    friend ostream& operator<<(ostream& out, const Box& b) {
        out << b.length << " " << b.height << " " << b.width;
        return out;
    }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
