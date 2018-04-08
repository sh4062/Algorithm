class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0)
            return 0;
        if (rotateArray.size() == 1)
            return rotateArray[0];

        int st=0;
        int end=rotateArray.size()-1;
        int mid=(st+end)/2;
        while(st<end){
            if(rotateArray[mid]==rotateArray[st])
                return rotateArray[mid+1];
            else if(rotateArray[mid]>rotateArray[st])
                st=mid;
            else
                end=mid;
            mid=(st+end)/2;
        }
        return 0;}
};