#ifndef INCLUDED_BL_ARRAY_H
#define INCLUDED_BL_ARRAY_H

#include <string>
#include <cassert>

using namespace std;

namespace LP {
    namespace simpleIndex {

	struct Security 
	{
	    string ticker;
	    string index;
	    int price;
	    Security(string t, int p) :
		ticker(t), price(p) {}
	};

	class Index 
	{
	    public:
		Index(const string& name);
		Index(const string& name, int cap);
		~Index();

		void insert(Security* sec);
		Security* find(const string& ticker);
		const Security* find(const string& ticker) const;

		void remove(const string& ticker);

		double calIndex() const;

	    private:
		int d_capacity;
		int d_size;
		Security **d_array;
		const string d_name;

		void clear();
		Security** initialize();
		void resize(int size);
	};
    }
}

#endif
