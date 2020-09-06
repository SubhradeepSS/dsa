void printNGE(int arr[], int n) { 
  stack < int > s; 
  s.push(arr[0]);
  for(int i=1;i<n;i++){
     while(!s.empty()&&arr[i]>s.top()){
         cout<<s.top()<<" "<<arr[i]<<endl;
         s.pop();
     }
     s.push(arr[i]);
  }
  while(!s.empty()){
      cout<<s.top()<<" -1"<<endl;
      s.pop();
  }
} 
