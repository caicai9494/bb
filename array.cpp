#include "array.h"


namespace LP {
    namespace simpleIndex {

	Index::Index(const string& name) :
	    d_capacity(10), d_size(0), d_array(initialize()), d_name(name) {}
	Index::Index(const string& name, int cap) :
	    d_capacity(cap >= 0 ? cap : 0), d_size(0), d_array(initialize()), d_name(name) {}

	Index::~Index() 
	{
	    clear();
	}

	void Index::clear()
	{
	    //d_size = d_capacity = 0;
	    delete []d_array;
	}

	Security** Index::initialize()
	{
	    assert(d_capacity >= 0);
	    Security** ret = new Security*[d_capacity];
	    return ret;
	}

	void Index::resize(int size)
	{
	    assert(size > d_capacity);
	    Index temp("", size);
	    int count = 0;
	    for(int i = 0; i < d_size; ++i)
	    {
		if(!(d_array[i]->index.empty()))
		{
		    temp.d_array[count] = d_array[i];
		    ++count;
		}
	    }

	    clear();
	    d_capacity = size;
	    d_size = count;
	    d_array = temp.d_array;
	    temp.d_array = NULL;
	}

	void Index::insert(Security* sec)
	{
	    assert(d_capacity >= 0);
	    assert(sec);

	    sec->index = d_name;

	    if(d_size >= d_capacity)
	    {
		resize(2 * d_capacity);
	    }
	    d_array[d_size] = sec;
	    ++d_size;
	}

	Security* Index::find(const string& ticker)
	{
	    for(int i = 0; i < d_size; ++i) 
	    {
		if(!(d_array[i]->index.empty()) && d_array[i]->ticker == ticker)
		    return d_array[i];
	    }
	    return NULL;
	}

	const Security* Index::find(const string& ticker) const
	{
	    for(int i = 0; i < d_size; ++i) 
	    {
		if(!(d_array[i]->index.empty()) && d_array[i]->ticker == ticker)
		    return d_array[i];
	    }
	    return NULL;
	}

	void Index::remove(const string& ticker)
	{
	    Security *sptr = find(ticker);
	    if(sptr) 
	    {
		sptr->index = "";
	    }
	}

	double Index::calIndex() const
	{
	    if(d_size == 0) 
	    {
		return 0.0;
	    }
	    else 
	    {
	        double sum = 0.0;
		int count = 0;
		for(int i = 0; i < d_size; ++i)
		{
		    if(!(d_array[i]->index.empty()))
		    {
			sum += d_array[i]->price;
			++count;
		    }
		}

		if(count == 0)
		{
		    return 0.0;
		}
		sum /= count;
		return sum;
	    }
	}

    }
}
