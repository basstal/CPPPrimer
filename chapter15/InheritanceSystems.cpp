class GraphicsFileFormats
{
public:
	GraphicsFileFormats(char[] data,std::size_t fileSize):fileSize(fileSize){}
	virtual ~GraphicsFileFormats() = default;
	virtual void openFile();
	std::size_t getSize() const;
protected:
	std::size_t fileSize;
	char[] data;
};

class GIFFileFormats : public GraphicsFileFormats
{
	virtual void openFile();
};

class TIFFFileFormats : public GraphicsFileFormats
{
	virtual void openFile();
};

class JPEGFileFormats : public GraphicsFileFormats
{
	virtual void openFile();
};

class BMPFileFormats : public GraphicsFileFormats
{
	virtual void openFile();
};