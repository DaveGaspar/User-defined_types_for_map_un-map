#include <iostream>
#include <map>
#include <unordered_map>

class A{
	private:
		int a;
		int b;
		int c;
	public:
		A() = delete;
		A(int a, int b, int c): a(a), b(b), c(c){}
		A(const A& obj) = default;
		A& operator=(const A& obj) = default;
		A(A&& obj) = default;
		A& operator=(A&& obj) = default;
		~A() = default;
	public:
		bool operator <(const A& obj) const{
			if ( (this->a + this->b + this->c) < (obj.a + obj.b + obj.c)){
				return true;
			}
			else{
				return false;
			}
		}
		bool operator==(const A& obj) const{
			return ((this->a == obj.a) && (this->b == obj.b) && (this->c == obj.c));
		}
		struct MyHashFunction{
			size_t operator()(const A& obj) const{
				return obj.a+obj.b+obj.c;
			}
		};

		friend std::ostream& operator << (std::ostream& os, const A& obj){
			os << obj.a << "," << obj.b << "," << obj.c;
			return os;
		}
};

int main(){
	A obj_1(7,5,1);
	A obj_2(4,5,6);
	A obj_3(3,2,4);

	std::map<A,int> m_map;

	m_map.insert(std::make_pair(obj_1,1));
	m_map.insert(std::make_pair(obj_2,2));
	m_map.insert(std::make_pair(obj_3,3));

	std::cout << "Overloading for map: " << std::endl;
	for (auto it : m_map){
		std::cout << it.first << " | " << it.second << std::endl;
	}	

	std::unordered_map<A,int,A::MyHashFunction> m_u_map;

	m_u_map.insert(std::make_pair(obj_1,1));
	m_u_map.insert(std::make_pair(obj_2,2));
	m_u_map.insert(std::make_pair(obj_3,3));

	std::cout << "\nOverloading for unordered_map: " << std::endl;
	for (auto it : m_u_map){
		std::cout << it.first << " | " << it.second << std::endl;
	}

	return 0;
}