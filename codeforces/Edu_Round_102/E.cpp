#include <iostream>
#include <vector>
#include <queue>
#include <optional>
//#include <array>
//#include <tuple>

using namespace std;

/*// Dijkstra algorithm
template<typename T>
class graph {
	template <typename T2>
	using twoby2_t = array<array<T2, 2>, 2>;
public:
	int n;
	vector<vector<pair<int, int>>> adj;
	vector<twoby2_t<optional<T>>> d;
	explicit graph(int _n) : n{_n}, adj(n), d(n) {}

	void dijkstra(int s) {
		vector<twoby2_t<bool>> found(n);
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < 2; ++j)
				for (int k{0}; k < 2; ++k)
					found[i][j][k] = false, d[i][j][k] = nullopt;
		d[s][0][0] = 0;

		using pq_t = pair<T, tuple<int, int, int>>;
		priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
		pq.emplace(0, typename pq_t::second_type{s, 0, 0});
		while (!pq.empty()) {
			auto [_, t]{pq.top()};
			auto [u, fs, fa]{t};
			pq.pop();
			if (found[u][fs][fa]) continue;
			found[u][fs][fa] = true;

			for (auto& [v, w] : adj[u]) {
				if (!d[v][fs][fa] || d[v][fs][fa] > d[u][fs][fa].value() + w) {
					d[v][fs][fa] = d[u][fs][fa].value() + w;
					pq.emplace(d[v][fs][fa].value(), typename pq_t::second_type{v, fs, fa});
				}
				if (!fs) // sub this edge
					if (!d[v][1][fa] || d[v][1][fa] > d[u][0][fa].value() + w - w) {
						d[v][1][fa] = d[u][0][fa].value() + w - w;
						pq.emplace(d[v][1][fa].value(), typename pq_t::second_type{v, 1, fa});
					}
				if (!fa) // add this edge
					if (!d[v][fs][1] || d[v][fs][1] > d[u][fs][0].value() + w + w) {
						d[v][fs][1] = d[u][fs][0].value() + w + w;
						pq.emplace(d[v][fs][1].value(), typename pq_t::second_type{v, fs, 1});
					}
				if (!fs && !fa) // sub && add (cancel out)
					if (!d[v][1][1] || d[v][1][1] > d[u][0][0].value() + w) {
						d[v][1][1] = d[u][0][0].value() + w;
						pq.emplace(d[v][1][1].value(), typename pq_t::second_type{v, 1, 1});
					}
			}
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	graph<long long> gph{n};
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		gph.adj[u].emplace_back(v, w);
		gph.adj[v].emplace_back(u, w);
	}

	gph.dijkstra(0);

	for (int i{1}; i < n; ++i) cout << gph.d[i][1][1].value() << " \n"[i == n - 1];
}*/ 

// Dijkstra algorithm
template <typename T>
class graph {
public:
    int n;
    vector<vector<pair<int, T>>> adj;
    vector<optional<T>> d;
    explicit graph(int _n) : n{_n}, adj(n), d(n) {}

    void dijkstra(int s) {
        vector<bool> found(n, false);
        fill(d.begin(), d.end(), nullopt);
        d[s] = 0;

        using pq_t = pair<T, int>;
        priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq{};
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [_, u]{pq.top()}; pq.pop();
            if (found[u]) continue;
            found[u] = true;
            for (auto& [v, w] : adj[u])
                if (!d[v] || d[v] > d[u].value() + w) {
                    d[v] = d[u].value() + w;
                    pq.emplace(d[v].value(), v);
                }
        }
    }
};

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, long long>>> adj(n);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	auto map = [&n](int u, bool fs, bool fa) {
		return u + 2 * fs * n + fa * n;
	};

	graph<long long> gph{4 * n};
	for (int u{0}; u < n; ++u)
		for (auto& [v, w] : adj[u]) {
			{
				auto x{map(u, 0, 0)};
				gph.adj[x].emplace_back(map(v, 0, 0), w);
				gph.adj[x].emplace_back(map(v, 1, 0), w - w);
				gph.adj[x].emplace_back(map(v, 0, 1), w + w);
				gph.adj[x].emplace_back(map(v, 1, 1), w - w + w);
			}
			{
				auto x{map(u, 1, 0)};
				gph.adj[x].emplace_back(map(v, 1, 0), w);
				gph.adj[x].emplace_back(map(v, 1, 1), w + w);
			}
			{
				auto x{map(u, 0, 1)};
				gph.adj[x].emplace_back(map(v, 0, 1), w);
				gph.adj[x].emplace_back(map(v, 1, 1), w - w);
			}
			{
				auto x{map(u, 1, 1)};
				gph.adj[x].emplace_back(map(v, 1, 1), w);
			}
		}


	gph.dijkstra(0);

	for (int i{1}; i < n; ++i) cout << gph.d[map(i, 1, 1)].value() << " \n"[i == n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
