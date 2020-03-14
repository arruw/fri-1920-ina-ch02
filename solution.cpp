#include <iostream>
#include <cmath>
#include <ctime>

#include <unistd.h>

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<int>> erdos_renyi_nm(const int n, const int m) {
  vector<vector<int>> G;
  G.resize(n);

  for(int x = 0; x < m; x++) {
    int i = rand() % n;
    int j = rand() % n;
    G[i].push_back(j);
    G[j].push_back(i);
  }

  return G;
}

unordered_set<int> plain_bfs(const vector<vector<int>> &G, vector<bool> &seen, const int root) {
  unordered_set<int> component;
  queue<int> frontier;

  frontier.push(root);
  seen[root] = true;

  while (!frontier.empty()) {
    const int i = frontier.front();
    component.insert(i);

    for (auto j : G[i]) {
      if (seen[j]) continue;
      seen[j] = true;
      frontier.push(j);
    }
    
    frontier.pop();
  }

  return component;
}

int plain_bfs_size(const vector<vector<int>> &G, vector<bool> &seen, const int root) {
  int componentSize = 0;
  queue<int> frontier;

  frontier.push(root);
  seen[root] = true;

  while (!frontier.empty()) {
    const int i = frontier.front();
    componentSize++;

    for (auto j : G[i]) {
      if (seen[j]) continue;
      seen[j] = true;
      frontier.push(j);
    }
    
    frontier.pop();
  }

  return componentSize;
}

vector<unordered_set<int>> connected_components(const vector<vector<int>> &G) {
  vector<bool> seen;
  seen.resize(G.size());
  vector<unordered_set<int>> components;
  
  for (int v = 0; v < G.size(); v++) {
    if (seen[v]) continue;
    const auto component = plain_bfs(G, seen, v);
    components.push_back(component);
  }
  
  return components;
}

unordered_set<int> biggest_connected_component(const vector<vector<int>> &G) {
  vector<bool> seen;
  seen.resize(G.size());
  unordered_set<int> component;
  int size = 0;

  for (int v = 0; v < G.size(); v++) {
    if (seen[v]) continue;
    const auto c = plain_bfs(G, seen, v);
    const auto s = c.size();
    if (s > size) {
      component = c;
      size = s;
    }
  }
  
  return component;
}

int biggest_connected_component_size(const vector<vector<int>> &G) {
  vector<bool> seen;
  seen.resize(G.size());
  int size = 0;

  for (int v = 0; v < G.size(); v++) {
    if (seen[v]) continue;
    const auto s = plain_bfs_size(G, seen, v);
    if (s > size) {
      size = s;
    }
  }
  
  return size;
}

void print_graph(const vector<vector<int>> G) {
  for (int i = 0; i < 10; i++)
  {
    cout << i << ": [";
    for (auto x : G[i])
    {
      cout << x << ", ";
    }
    cout << "]" << endl;
  }
}

void print_component(const unordered_set<int> &component) {
  cout << "{";
  for (auto v : component) {
    cout << v << ", ";
  }
  cout << "}" << endl;
}

int main(int argc, char const *argv[]) {
  const vector<int> tests = {
    //(int)1e3,
    //(int)1e4,
    //(int)1e5,
    //(int)1e6,
    //(int)5e6,
    //(int)10e6,
    //(int)15e6,
    //(int)20e6,
    //(int)25e6,
    //(int)30e6,
    //(int)35e6,
    //(int)37e6,
    //(int)39e6,
    (int)40e6,
  };

  cout << "n, m, Tg, Ts, T, S" << endl;
  for (auto n : tests)
  {
    const int m = (n*log10(n))/8;

    time_t start = time(0);
    const auto G = erdos_renyi_nm(n, m);
    const auto Tg = time(0) - start;

    start = time(0);
    const auto S = biggest_connected_component_size(G);
    const auto Ts = time(0) - start;

    const auto T = Tg + Ts;

    cout << n << ", " << m << ", " << Tg << ", " << Ts << ", " << T << ", " << S << endl;
    
    usleep(60e6);
  }

  return 0;
}

