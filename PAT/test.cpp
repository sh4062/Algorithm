    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int b = matrix.size();
        if(b==0) return res;
        int a = matrix[0].size();
        if(b==1)return matrix[0];
        int i = -1,j=-1;
        int m =a*b;
        int layer = 1;
        if(a==1){
            for( ++i ;i<b;i++)
            res.push_back(matrix[i][0]);
            return res;
        }
        int c =0;
        //while(i<a&&j<b){
            
              
        for( c=i ;c<a;c++){
            res.push_back(matrix[j][c]);
            if(res.size()==m)return res;
        }
        j++;
       
        for( c=j ;c<b;c++){
            res.push_back(matrix[c][a-1]);
            if(res.size()==m)return res;
        }
        a--;
        
         for( c=a-1;c>=i&&b-1>=j;c--){
           res.push_back(matrix[b-1][c]);
             if(res.size()==m)return res;
        }
        b--;
        
        for( c=b-1 ;c>=j&&a-1>=i;c--){
            res.push_back(matrix[c][i]);
            if(res.size()==m)return res;
         }
        i++;
   
         
       //}
        return res;
        
        
    }