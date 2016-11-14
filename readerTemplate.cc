#include <vector>
#include <iostream>

// read in a Wavefront object file 
// data format can be found at  https://en.wikipedia.org/wiki/Wavefront_.obj_file#Face_Elements

void YOURCLASSNAME::readData (const string& _modelfilename )
{
    // this bit reads in the path to your ANGELDIR directory via the
    // environment variable
    string evname = "ANGELDIR";
    string path = PCGeneralIO::getEnvironmentVariable(evname);

    // assuming the data is in a subdirectory called DATA
    path += "/data/";

    // append filename to path
    string file = path + _modelfilename;

    // open an input file stream
    ifstream inFile;
    inFile.open(file.c_str());
    if (!inFile)
    {
        cout << "Error: unable to open file: "
            << file << endl;
        exit (1);
    }

    // read in all the data, and close the file
    vector<string> fileLines;
    string tempString;
    while (inFile >> tempString)
    {
        fileLines.push_back(tempString);
    }
    inFile.close();

    // set aside some data structures to store vertices, normals, and faces
    // NOTE: what you do with these and how you get them out of this function depends
    // on your implementation
    vector<vector< float > > vertices;
    vector<vector< float > > normals;
    vector<vector< int   > > faces;


    // set aside temp vector variables to store the data on a per-line basis
    vector<float> floats;
    vector<int>   ints;
    // now step through each line and interpret the data using the functions in generalio.h
    for (unsigned int i=0; i<fileLines.size(); i++)
    {
        string currentLine = fileLines[i];
        if (currentLine.size() > 1) {
            if ( !(currentLine.substr(0,1) == "#") )  // ignore comment lines that start with "#"
            {
                if (currentLine[i].substr(0,2) == "vn") //  this is a vertex normal
                {
                    // split on spaces
                    vector<string> normalAsString = PCGeneralIO::splitString(currentLine," ");
                    float x = PCGeneralIO::stringToReal(normalAsString[1]);
                    float y = PCGeneralIO::stringToReal(normalAsString[2]);
                    float z = PCGeneralIO::stringToReal(normalAsString[3]);

                    vector<float> tempnormal;
                    tempnormal.push_back(x);
                    tempnormal.push_back(y);
                    tempnormal.push_back(z);

                    normals.push_back(tempnormal);

                }
                else if (currentLine[i].substr(0,2) == "v") // this is a vertex
                {
                    // split on spaces
                    vector<string> vertexAsString = PCGeneralIO::splitString(currentLine," ");
                    float x = PCGeneralIO::stringToReal(vertexAsString[1]);
                    float y = PCGeneralIO::stringToReal(vertexAsString[2]);
                    float z = PCGeneralIO::stringToReal(vertexAsString[3]);

                    vector<float> tempvertex;
                    tempvertex.push_back(x);
                    tempvertex.push_back(y);
                    tempvertex.push_back(z);

                    vertices.push_back(tempvertex);
                }
                else if (currentLine[i].substr(0,2) == "f") // these are face indices, starting at 1, just to be complicated ;-)
                {
                    // note: subtracting one to each vertex index to correspond to actual indices in c-style data structure above
                    // split on spaces
                    vector<string> faceIndicesAsString = PCGeneralIO::splitString(currentLine," ");
                    vector<string> aBits = PCGeneralIO::splitString(faceIndicesAsString[1],"//");
                    int a = PCGeneralIO::stringToInt(aBits[0]) - 1 ;

                    vector<string> bBits = PCGeneralIO::splitString(faceIndicesAsString[2],"//");
                    int b = PCGeneralIO::stringToInt(bBits[0]) - 1;

                    vector<string> cBits = PCGeneralIO::splitString(faceIndicesAsString[3],"//");
                    int c = PCGeneralIO::stringToInt(cBits[0]) - 1 ;

                    vector<int> tempface;
                    tempface.push_back(a);
                    tempface.push_back(b);
                    tempface.push_back(c);

                    faces.push_back(tempface);

                }
            }
        }
    }


//  convert to a number
//        float number = PCGeneralIO::stringToReal(tempString);


}
