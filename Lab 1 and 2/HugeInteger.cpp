#include "HugeInteger.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;


HugeInteger::HugeInteger(const std::string& val)
{


	if (val.length() == 0)
	{
		throw std::invalid_argument("ERROR");
	}

	int i = 0;
	if(val[0] == '-')
	{
		minus = true;
		i++;
	}

	else
	{
		minus = false;
	}

	while(i < val.length())
	{

		if( (val[i] - '0') > 9 || (val[i] - '0') < 0)
		{
			throw std::invalid_argument("ERROR");
		}

		vec.push_back((val[i] - '0'));
		i++;
	}

}

HugeInteger::HugeInteger(int n)
{

	if(n > 0)
	{


		for(int i = 1; i <= n; i++)
		{
			vec.push_back(rand()%10);

			if(i == 0 && vec[i] == 0)
			{
				vec.insert(vec.begin(),1);
			}

		}
	}

	else
	{
		throw std::invalid_argument("ERROR");
	}




}

HugeInteger::HugeInteger(std::vector<int>& h)
{
	vec = h;
}

HugeInteger HugeInteger::add(const HugeInteger& h){

	vector<int> vec_add;
	
	int size_1 = vec.size();
	int size_2 = h.vec.size();
	int shift = 0, temp_sum = 0;
	int a = 0, b = 0, c = 0;


	if( (this -> minus == 0 && h.minus == 0) || (this -> minus == 1 && h.minus == 1) )
	{

		if (size_1 >= size_2)
		{
			a = size_1 - 1;
			b = size_2 - 1;
			c = size_1 -1;


			while(b>=0){
				temp_sum = vec[a] + h.vec[b] + shift;
				vec_add.insert(vec_add.begin(),(temp_sum%10));
				shift = temp_sum/10;

				a--;
				c--;
				b--;
			}

			while(a >= 0)
			{
				temp_sum = vec[a] + shift;
				vec_add.insert(vec_add.begin(),(temp_sum%10));
				shift = temp_sum/10;

				a--;
				c--;
			}
			if(shift == 1)
			{
				vec_add.insert(vec_add.begin(),(shift));
			}
		}

		else if(size_2 > size_1)
		{
			b = size_1 - 1;
			a = size_2 - 1;
			c = size_2 - 1;

			while(b >= 0)
			{
				temp_sum = vec[b] + h.vec[a] + shift;
				vec_add.insert(vec_add.begin(),(temp_sum%10));
				shift = temp_sum/10;

				a--;
				c--;
				b--;
			}

			while(a >= 0)
			{
				temp_sum = h.vec[a] + shift;
				vec_add.insert(vec_add.begin(),(temp_sum%10));
				shift = temp_sum/10;

				a--;
				c--;
			}

			if(shift == 1)
			{
				vec_add.insert(vec_add.begin(),(shift));
			}

		}
		if (vec_add[0] == 0 && vec_add.size() != 1)
		{
				vec_add.erase(vec_add.begin());
		}
		
		HugeInteger res = HugeInteger(vec_add);
		
		if (this->minus == 1 && h.minus == 1)
		{
			res.minus = 1;
		}
		return res;
	}

	else if(this->minus == 0 && h.minus == 1)
	{
		HugeInteger vec2_copy(h);
		vec2_copy.minus = 0;
		HugeInteger res = this->subtract(vec2_copy);
		return res;
	}
	
	else
	{
		HugeInteger vec2_copy(*this);
		HugeInteger vec1_copy(h);
		vec2_copy.minus = 0;
		HugeInteger res = vec1_copy.subtract(vec2_copy);
		return res;
	}

}
HugeInteger HugeInteger::subtract(const HugeInteger& h) 
{

	if (compareTo(h) == 0)  // if numbers are equivalent, difference will be 0
	{
		return HugeInteger("0");
	}
	
	if (this -> minus == false && h.minus == true)
	{         // If second vec is pos and first vec is neg
		HugeInteger vec1_copy(*this);
		HugeInteger vec2_copy(h);
		vec2_copy.minus = 0;
		HugeInteger output = vec1_copy.add(vec2_copy);
		return output;
	}

	else if (this -> minus == true && h.minus == false)
	{   // If second vec is pos and first vec is neg

		HugeInteger vec1_copy(*this);
		HugeInteger vec2_copy(h);
		vec1_copy.minus = 0;
		HugeInteger output = vec1_copy.add(vec2_copy);
		output.minus = 1;
		return output;
	}

	int shift = 0, diff_sub = 0;
	int vec1_size = vec.size(); int vec2_size = h.vec.size();

	vector <int> num_1; vector <int> num_2; vector <int> diff;

	if (vec1_size != vec2_size) // If not the same size
	{
		if (vec1_size < vec2_size)
		{         //num 2 is set to the SHORTER value
			num_2 = vec;
			num_1 = h.vec;
		}

		else
		{
			num_1 = vec;
			num_2 = h.vec;
		}
	}

	else
	{
		if ((h.minus == 1 && this -> minus == 1 && this -> compareTo(h) > 0) || (h.minus == 0 && this -> minus == 0 && this -> compareTo(h) < 0))
		{ //num_2 holds the SMALLER value

				num_2 = vec;
				num_1 = h.vec;
		}
			else
			{
				num_2 = h.vec;
				num_1 = vec;
			}
	}


	std::reverse(num_1.begin(), num_1.end());
	std::reverse(num_2.begin(), num_2.end());

	for (int i = 0; i < num_2.size(); i++) // This loop will go through each element and find the diff for element i in both vectors.
	{

		diff_sub = num_1[i] - num_2[i] - shift;   // We store our value in a variable called (diff_sub).

		if (diff_sub < 0)
		{                      //if diff_sub is non-positive, it will have a carry.
			diff_sub = diff_sub + 10;          // diff_sub needs to be appended.
			shift = true; // Our carry var
		}
		else
		{
			shift = false; // No carryover required here (+)
		}

		diff.push_back(diff_sub);               //push the value of diif_sub into the back of diff.
	}

	for (int i = num_2.size(); i < num_1.size(); i++)
	{
		diff_sub = num_1[i] - shift;

		if (diff_sub < 0)
		{
			diff_sub = diff_sub + 10;
			shift = true;
		}

		else
		{
			shift = false;
		}

		diff.push_back(diff_sub);
	}
	std::reverse(diff.begin(), diff.end());      // Our final value will be in reverse order, so we must use the built-in func reverse.

	while (diff[0] == 0) // This while-looop will remove any 0 before the start of any non-zero value.
	{
		diff.erase(diff.begin());
	}

	HugeInteger output(diff);

	if (compareTo(h) < 0) // If we do a comparison and found the value to be non-positive.
	{
		output.minus = true;
	}

	return output;


}

HugeInteger HugeInteger::multiply(const HugeInteger& h)
{

	int shift = 0, temp_prod = 0;
	int size_1 = vec.size();
	int size_2 = h.vec.size();
	
	//Our index counters
	int c_index1 = 0;
	int c_index2 = 0;

	vector<int> product(size_2 + size_1, 0);
	HugeInteger* output;

	if (vec[0] == 0 || h.vec[0] == 0)
	{
		return HugeInteger("0");
	}


	for (int i = (size_1 - 1); i >= 0; i--)
	{

		shift = 0;
		c_index2 = 0;

		for (int j = (size_2 - 1); j >= 0; j--)
		{
			temp_prod = vec[i] * h.vec[j] + product[c_index1 + c_index2] + shift;
			product[c_index1 + c_index2] = temp_prod % 10;  //our appended
			shift = temp_prod/10;                //carryer
			c_index2++;                              //increment our index counter
		}
		
		if (shift > 0)
		{
			product[c_index1 + c_index2] += shift;
		}
		
		c_index1++;                                  //increment counter
	}
	std::reverse(product.begin(), product.end());  // Reverse the answer

	if (product[0] == 0) // If it contains any 0's in the front of a number
	{
		product.erase(product.begin()); // Delete them
	}

	HugeInteger* temp = new HugeInteger(product);  //creates a new HugeInteger of product and temp points to it
	output = temp;                                    // make res and temp point to the same thing

	 if ((this->minus == 1 && h.minus == 0) || (this->minus == 0 && h.minus == 1)) // - * + = -
	 {

		 output -> minus = true;
	 }

	return *output;    //return the object res was pointing to (product)
}

int HugeInteger::compareTo(const HugeInteger& h) 
{
	
	int result = 0;
	int size_1 = vec.size();
	int size_2 = h.vec.size();

	if (toString() == h.toString())
	{
		return 0; // It equals
	}

	if (minus == false && h.minus == false)
	{  //if both are non-negative

		if (size_2 > size_1)
		{
			result = -1;
		}
		
		else if (size_2 < size_1)
		{
			result = 1;
		}
		
		else if (size_2 == size_1)
		{
			if (h.vec[0] > vec[0])
			{
				result = -1;
			}
			else
			{
				result = 1;
			}
		}
	}

	else if (h.minus == false && minus == true)
	{
		result = -1;
	}
	
	else if (h.minus == true && minus == false)
	{
		result = 1;
	}
	
	else if (minus == true && h.minus == true)
	{ //If they're both minus

		if (size_2 > size_1)
		{
			result = 1;
		}
		
		else if (size_2 < size_1)
		{
			result = -1;
		}
		
		else if (size_2 == size_1) // What if both are minus
		{
			if (h.vec[0] > vec[0])
			{
				result = 1;
			}
			
			else
			{
				result = -1;
			}
		}
	}

	return result;
}

std::string HugeInteger::toString() const
{

	string str_origin = ""; int n = vec.size();

	if(minus == true)
	{
		str_origin.push_back('-');
	}

	for (int k = 0; k < n; k++)
	{
		str_origin.push_back(vec[k] + '0');
	}

	return str_origin;
}
