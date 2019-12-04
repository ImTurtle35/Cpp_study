class Integer {
public:
	Integer(int i = 0);
	~Integer();
	void setInteger(int i);
	int getInteger() const;
private:
	int value;
};