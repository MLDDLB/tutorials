#include <map>
#include <iostream>


template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		if (!(keyBegin < keyEnd))
			return;

		auto up_it = m_map.upper_bound(keyEnd);
		if (up_it == m_map.begin()) {
			if (!(val == m_valBegin))
				m_map[keyBegin] = val;
		}
		else {
			auto low_it = --up_it;
			while (low_it != m_map.begin() && keyBegin < low_it->first) {
				low_it--;
			}

			if (up_it->first < keyEnd) {
				up_it++;
			}

			if (up_it == m_map.end() || !(up_it->second == val)){
				if (low_it->first < keyBegin && !(low_it->second == val)) {
					m_map.erase(++low_it, up_it);
					m_map[keyBegin] = val;
				}
				else if (!(low_it->first < keyBegin) && !(val == m_valBegin)) {
					m_map.erase(low_it, up_it);
					m_map[keyBegin] = val;
				}
			}
		}
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};


void print_interval(const auto& m, const auto& begin, const auto& end) {
	for (auto i {begin}; i < end; i++) {
		std::cout << "m[" << i << "] = " << m[i] << " ";
	}
	std::cout << std::endl;
}


int main ()
{
	interval_map<int, char> m {40};
	std::cout << "m[0] = " << m[0] << " m[100] = " << m[100] << std::endl;
	m.assign(0, 4, 'a');
	m.assign(8, 12, 'c');
	m.assign(4, 8, 'b');
	m.assign(0, 4, 'e');
	m.assign(-4, 0, 'd');
	print_interval(m, -15, 15);
	m.assign(2, 6, 'a');
	m.assign(2, 6, 'c');
	m.assign(-2, 6, 'l');
	print_interval(m, -15, 15);
	return 0;
}