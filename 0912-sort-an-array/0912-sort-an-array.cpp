class Solution {
public:
    void merge(vector<int>&arr,int s,int e)
{
	int mid=s+(e-s)/2;
	int len1=mid-s+1;
	int len2=e-mid; 
	
	int *first=new int[len1];
	int *second=new int[len2];
	
	int m_arr_ind = s;
	//sorting left part using recursion
	for(int i=0;i<len1;i++)
	{
		first[i]=arr[m_arr_ind];
		m_arr_ind++;
	}
	
	m_arr_ind = mid+1;
	//sorting right part using recursion
	for(int i=0;i<len2;i++)
	{
		second[i]=arr[m_arr_ind];
		m_arr_ind++;
	}
	
	int ind1=0;
	int ind2=0;
	m_arr_ind=s;
	while(ind1<len1 && ind2<len2)
	{
		if(first[ind1]<second[ind2])
		{
			arr[m_arr_ind]=first[ind1];
			m_arr_ind++;
			ind1++;
		
		}
		else
		{
			arr[m_arr_ind]=second[ind2];
			m_arr_ind++;
			ind2++;
		}
	}
	while(ind1<len1)
	{
		arr[m_arr_ind]=first[ind1];
		m_arr_ind++;
		ind1++;
	}
	while(ind2<len2)
	{
		arr[m_arr_ind]=second[ind2];
		m_arr_ind++;
		ind2++;
	}
	delete []first;
    delete []second;
}

    void mergesort(vector<int>&arr,int s,int e)
{
	if(s>=e)
	return ;
	int mid=s+(e-s)/2;
	//sort left part
	mergesort(arr,s,mid);
	//sort right part
	mergesort(arr,mid+1,e);
	//merge them
	merge(arr,s,e);
}

    vector<int> sortArray(vector<int>& arr) 
    {
        int s=0;
        int e=arr.size()-1;
        mergesort(arr,s,e);

        
        return arr;



    }
};