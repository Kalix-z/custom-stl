namespace kstd {
 
 #include <string.h>



class string {
private:
	char* m_cstr;
	size_t m_size;
public:
	string() {
		m_cstr = new char[1];
		m_cstr[0] = '\0';
		m_size = 0;
	}
	
	string(const string& old) {
		m_cstr = new char[old.size() + 1];
		memcpy(m_cstr, old.c_str(), old.size() + 1);
		m_size = old.size();
	}

	string(const char* _str) {
		m_size = strlen(_str);
		m_cstr = new char[m_size+1];
		memcpy(m_cstr, _str, m_size+1);
	}	

	void operator+=(const string& _val) {
		char* newBuf = new char[_val.size() + m_size + 1];		
		memcpy(newBuf, m_cstr, m_size);
		memcpy(newBuf + m_size, _val.c_str(), _val.size() + 1);
		delete[] m_cstr;
		m_cstr = newBuf;
		m_size += _val.size();
	}

	string operator+(const string& other) {
		char* newBuf = new char[other.size() + m_size + 1];
		memcpy(newBuf, m_cstr, m_size);
		memcpy(newBuf + m_size, other.c_str(), other.size() + 1);
		return newBuf;
	}

	void operator+=(char val) {
		char* newBuf = new char[m_size + 2];
		memcpy(newBuf, m_cstr, m_size);
		newBuf[m_size] = val;
		newBuf[m_size + 1] = '\0';
		delete[] m_cstr;
		m_cstr = newBuf;
	}

	void operator=(const char* other) {
		m_size = strlen(other);
		m_cstr = new char[m_size + 1];
		memcpy(m_cstr, other, m_size + 1);
	}

	void operator=(const string& other) {
		m_cstr = new char[other.size() + 1];
		memcpy(m_cstr, other.c_str(), other.size() + 1);
		m_size = other.size();
	}

	char* c_str() const {
		return m_cstr;
	}

	size_t size() const {
		return m_size;
	}

	~string() {
		delete[] m_cstr;		
	}
}; 
 
  
  
}
