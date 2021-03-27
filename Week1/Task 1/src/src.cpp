#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
	explicit Logger(ostream& output_stream) 
		: os(output_stream) {}

	void SetLogLine(bool value) { log_line = value; }
	void SetLogFile(bool value) { log_file = value; }

	void SetLine(int linenum)
	{
		line = linenum;
	}

	void SetFile(const string& filename)
	{
		file = filename;
	}

	void Log(const string& message);

private:
	ostream& os;
	bool log_line = false;
	bool log_file = false;
	string file;
	int line;
};

void Logger::Log(const string& message)
{
	if (log_line && log_file)
	{
		os << file << ':' << line << ' ';
	}
	else if (log_line)
	{
		os << "Line " << line << ' ';
	}
	else if (log_file)
	{
		os << file << ' ';
	}
	os << message << endl;
}


#define LOG(logger, message)	\
	logger.SetLine(__LINE__);	\
	logger.SetFile(__FILE__);	\
	logger.Log(message);