void build(int* segment,int* arr,int s,int e,int idx)
{
    if(s==e)
    {
        segment[idx]=arr[s];
        return;
    }
    int m=(s+e)/2;
    build(segment,arr,s,m,2*idx+1);
    build(segment,arr,m+1,e,2*idx+2);
    // opeartion
    segment[idx]=max(segment[2*idx+1],segment[2*idx+2]);
}
int query(int * segment,int * arr,int s,int e,int l,int r ,int idx)
{
    if(s>=l && e<=r)
    {
        return segment[idx];
    }
    if(s>r || e<l)
    {
        return 0;
        //depending upon opeartion
    }
    int m=(s+e)/2;
    // opeartion
    return max(query(segment,arr,s,m,l,r,2*idx+1),query(segment,arr,m+1,e,l,r,2*idx+2));
}
void update(int * segment,int * arr,int s,int e,int i,int val,int idx)
{
    if(e<s)
    return;

    if(s==e)
    {
        segment[idx]=val;
    }
    else
    {
        int m=(s+e)/2;
        if(i<=m)
        {
            update(segment,arr,s,m,i,val,2*idx+1);
        }
        else
        {
            update(segment,arr,m+1,e,i,val,2*idx+2);
        }
        // opeartion
        segment[idx]=max(segment[2*idx+1],segment[2*idx+2]);
    }

}