//Union - Find implementation
int parent[200001], size[200001];

int Find(int i){
  if(i == parent[i]) return i;
  parent[i] = Find(parent[i]);
  return parent[i];
}

bool Union(int x, int y){
  int a = Find(x), b = Find(y);

  if(a == b) return false;

  if(size[a] == size[b]){
    size[b]++;
    parent[a] = b;
  } else if(size[a] < size[b]){
    parent[a] = b;
  } else{
    parent[b] = a;
  }

  return true;
}

void init(int n){
  memset(size, 0, sizeof size);
  for(int i=0; i<n; i++) parent[i] = i;
}