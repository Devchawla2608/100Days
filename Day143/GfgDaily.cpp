	void shuffleArray(int arr[],int n)
	{
	    vector<int> vec;
        int ind=n/2;
        for(int i=0;i<n/2;i++)
        {
            vec.push_back(arr[i]);
            vec.push_back(arr[ind]);
            ind++;
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=vec[i];
        }
	}