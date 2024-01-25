#include<iostream>
#include<map>
#include<limits>
#include<string>

template<typename K, typename V>
class Interval_Map{
    std::map<K, V> m_map;
    V m_valBegin;

public:
  Interval_Map(V const& val) : m_valBegin(val){}
  
    void assign(K const& keyBegin, K const& keyEnd, V const& val){
        if(!(keyBegin < keyEnd))
            return;
        auto itrBegin = m_map.lower_bound(keyBegin);
        auto itrEnd   = m_map.upper_bound(keyEnd);

        V tempEndval = (itrEnd == m_map.begin()) ? m_valBegin : std::prev(itrEnd)->second;

        bool beginFlag = (this->operator[](keyBegin) == val);
        bool endFlag = (this->operator[](keyEnd) == val);

        bool diagFlag = 1;
   
        V edgeBegin = (itrBegin == m_map.begin()) ? m_valBegin : std::prev(itrBegin)->second;
        if((edgeBegin == val) && (val != this->operator[](keyBegin)))
            diagFlag = 0;
        if((edgeBegin != val) && (val == this->operator[](keyBegin)))
            beginFlag = 0;

        if((m_map.size() > 0) && (itrBegin != itrEnd)){
            m_map.erase(itrBegin, itrEnd);
        }
        
        if(!beginFlag && diagFlag)
            m_map.insert(std::pair<K, V>(keyBegin, val));
        if(!endFlag)
            m_map.insert(std::pair<K, V>(keyEnd, tempEndval));
       
    }

    int size(){
        return m_map.size();
    }

    V const& operator[](K const& key) const{
        auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
       // return (--m_map.upper_bound(key))->second;
    }
    
    const std::map<K, V>& getMap(){
        return m_map;
    } 
};

template<typename K, typename V>
void print_interval_map(Interval_Map<K, V>& map){
    const std::map<K, V>& mp = map.getMap();
    for(auto const& pair : mp){
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
}


struct TestKeyType
{
    unsigned int val;
    constexpr TestKeyType(unsigned int val) : val(val) {}
    constexpr bool operator<(const TestKeyType& other) const { return val < other.val; }
};

namespace std {
    template<> class numeric_limits<TestKeyType> {
    public:
        static constexpr TestKeyType lowest() { return TestKeyType(numeric_limits<unsigned int>::lowest()); }
        //static constexpr TestKeyType lowest() { return TestKeyType(-250); }
    };
}

using TestValueType = char;

struct TestFloatKeyType
{
    float val;

    TestFloatKeyType() = default;

    TestFloatKeyType(float val) : val(val) {}
    bool operator< (TestFloatKeyType other) const
    {
        return other.val - val > 1.e-4f;
    }
};

namespace std {
    template<> class numeric_limits<TestFloatKeyType> {
    public:
        static TestFloatKeyType lowest() { return TestFloatKeyType(numeric_limits<float>::lowest()); }
    };
}

int main(){
    
   // std::cout << std::numeric_limits<int64_t>::lowest() << std::endl;
  //  Interval_Map<TestKeyType, TestValueType> map{'A'};
   // m.assign(1, 15, 'B');

  // Interval_Map<TestKeyType, TestValueType> map('A');
  //  m.assign(1, std::numeric_limits<int>::max(), 'B');
    Interval_Map<int, char> map{'A'};

   // m.assign(3, 6, 'B');
   // m.assign(2, 5, 'C');
   // m.assign(4, 7, 'A');

   // map.assign(std::numeric_limits<int>::lowest(), 5, 'B');
    map.assign(4, 10, 'b');
    map.assign(10, 50, 'C');
    map.assign(4, 10, 'C');

   // map.assign(1, 10, 'C');
   // map.assign(1, 4, 'C');
    //  Assign values to intervals
  //  map.assign(std::numeric_limits<int>::lowest(), 2,'B');
    //  m.assign(3, 6, 'B');
 //   m.assign(2, 5, 'C');
 //   m.assign(4, 7, 'A');
   // map.assign(1, 10, 'C');
   // map.assign(1, 4, 'C');
  //  map.assign(3, 14, 'D');
  //  map.assign(14, 15, 'E');
    

  //  Interval_Map<TestKeyType, TestValueType> map('A');
  //  map.assign(1, 3, 'B');
   // map.assign(6, 8, 'C');

    // Print the interval_map
    print_interval_map(map);
   // std::cout << m[255] << std::endl;
    // Test interval mappings
    std::cout << "Value at key 0: " << map[0] << std::endl;       // 'A'
    std::cout << "Value at key 4: " << map[4] << std::endl;       // 'B'
    std::cout << "Value at key 6: " << map[6] << std::endl;       // 'A'
    std::cout << "Value at key 7: " << map[7] << std::endl;     // 'A'
    std::cout << "Value at key 9: " << map[9] << std::endl;     // 'D'
   // std::cout << "Value at key 16: " << map[16] << std::endl;     // 'A'


    return 0;
}
