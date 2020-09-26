int lower_b(int l,int r,int n){
  while(l<=r){
    //cout<<l<<" "<<r<<endl;a
    int mid=(l+r)/2;
    if(n>b[mid]) l=mid+1;
    else r=mid-1;
  }
  return l;
}
int lower_b(int l,int r,int n){
  while(r-l>1){
    //cout<<l<<" "<<r<<endl;a
    int mid=(l+r)/2;
    if(n>b[mid]) l=mid;
    else r=mid;
  }
  return l;
}
