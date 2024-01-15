class Solution {
public:
     bool isValidSerialization(string pre) {
        
        int vac=1;
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==',')
                continue;
            
            
            vac--;
           
            while(i<pre.size() && pre[i]>='0'&&pre[i]<='9'&&pre[i]!=',')i++;
           
            if(vac<0)
                return false;

            if(pre[i]!='#')
                vac+=2;
        }
        
        if(vac)
            return false;
        return true;
    }
};
