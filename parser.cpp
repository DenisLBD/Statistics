#include "measurement.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <vector>


//функция подсчета слов в строке
int countWords(std::string str)
{
    if (str == "")
        return 0;

    bool inSpaces = true;
    int numWords = 0;
    int i = 0;

    while (i != str.length())
    {
        if (std::isspace(str[i]))
        {
            inSpaces = true;
        }
        else if (inSpaces)
        {
            numWords++;
            inSpaces = false;
        }

        ++i;
    }
    return numWords;
}

//функция задания слову определенной длины
std::string makeDefLength(std::string str, int newLength)
{
    std::string newStr = str;

    if (str.length() >= newLength)
    {
        str = str.substr(0, newLength);
        return str;
    }

    while (newStr.length() < newLength)
    {
        newStr.push_back(' ');
    }

    return newStr;
}

//функция считывания колонки по ее номеру. Отсчет начинается с нуля
//в качестве маркера конца колонки используется END
//результат чтения выводится на экран, а также записывается в массив "column"
std::vector<Measurement> readColumn(std::string fileName)
{
    std::vector<Measurement> column;
    std::ifstream fileData(fileName);

    if (!fileData)
    {
        std::cerr << "Can't open data file" << std::endl;
        exit(1);
    }

    std::string firstLine = "";
    std::string line = "";
    int number = 1;
    double data = 0;
    double time = 0.25;

    Measurement measurement;

    getline(fileData, firstLine);

    //работа с информацией из файла
    while (getline(fileData, line))
    {
        if (line == "")
        {
            std::cout << "END\n" << std::endl;
            fileData.close();
            return column;
        }

        measurement.setData(std::stod(line));
        std::cout << line << std::endl;

        measurement.setNumber(number);
        measurement.setTime(time);

        number++;
        time += 0.25;

        column.push_back(measurement);
    }

    fileData.close();
    return column;
}

//функция выделения фрагмента с определенным порогом
std::vector<Measurement> makeFragment(std::vector<Measurement> sourceData, double threshold)
{
    std::vector<Measurement> fragment;

    int i = 0;

    while (i < sourceData.size())
    {
        if (sourceData[i].getData() > threshold)
        {
            fragment.push_back(sourceData[i]);
        }
        i++;
    }
    return fragment;
}

//функция записи фрагментов в файл
//возможно разбиение на несколько столбцов
void splitData(std::vector<Measurement> data, std::string nameCol, std::string outputFileName, int isAdditional, int splitNumber, int isAdvansed = 0)
{
    if (isAdditional == 0)
        splitNumber = data.size();

    //число колонок элементов
    int numCol = ceil((data.size() * 1.0) / splitNumber);

    std::vector<std::vector<Measurement>> splitTable;
    splitTable.assign(splitNumber, std::vector<Measurement>(numCol));

    int k = 0; //индекс элемента массива
    for (int i = 0; i < numCol; i++)
    {
        for (int j = 0; j < splitNumber; j++)
        {
            splitTable[j][i] = data[k];
            k++;
            if (k == data.size())
                break;
        }
    }

    //записываем данные в файл
    std::ofstream out(outputFileName, std::ios::out);

    if (!out)
    {
        std::cerr << "Can't save information in file";
        exit(1);
    }

    std::string dataToWrite = "";

    if (isAdditional == 0 && isAdvansed == 0)
    {
        nameCol = makeDefLength(nameCol, 10);
        out << nameCol;

        out << '\n';

        for (int i = 0; i < splitTable.size(); i++)
        {
            dataToWrite = makeDefLength(std::to_string(splitTable[i][0].getData()), 8);

            out << dataToWrite << "  ";

            out << '\n';
        }
    }
    else if (isAdditional == 1 && isAdvansed == 0)
    {
        //для additional fragmentation
        nameCol.push_back('_');

        std::string tmp = "";

        for (int i = 0; i < numCol; i++) //названия подстолбцов
        {
            tmp = nameCol;
            tmp += char(i + 65);
            tmp = makeDefLength(tmp, 10);

            out << tmp;
        }

        out << "\n";

        for (int i = 0; i < splitNumber; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                if (splitTable[i][j].getNumber() == 0)
                {
                    out << makeDefLength(" ", 10);;
                    break;
                }

                dataToWrite = makeDefLength(std::to_string(splitTable[i][j].getData()), 8);

                out << dataToWrite << "  ";
            }

            out << "\n";
        }

        out << "\n";
    }
    else if (isAdditional == 0 && isAdvansed == 1)
    {
        //для not additional + advansed fragmentation 
        nameCol = makeDefLength(nameCol, 30);
        out << nameCol;

        out << '\n';

        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                out << "NUMBER    ";
            else if (i == 1)
                out << "DATA      ";
            else
                out << "TIME      ";
        }

        out << '\n';

        for (int i = 0; i < splitTable.size(); i++)
        {
            dataToWrite = makeDefLength(std::to_string(splitTable[i][0].getNumber()), 8);

            out << dataToWrite << "  ";

            dataToWrite = makeDefLength(std::to_string(splitTable[i][0].getData()), 8);

            out << dataToWrite << "  ";

            dataToWrite = makeDefLength(std::to_string(splitTable[i][0].getTime()), 8);

            out << dataToWrite << "  " << '\n';
        }
    }
    else if (isAdditional == 1 && isAdvansed == 1)
    {
        //для additional + advansed fragmentation
        nameCol.push_back('_');

        std::string tmp = "";

        for (int i = 0; i < numCol; i++) //названия подстолбцов
        {
            tmp = nameCol;
            tmp += char(i + 65);
            tmp = makeDefLength(tmp, 30);

            out << tmp;
        }

        out << '\n';

        for (int j = 0; j < numCol; j++) //задаем названия колонок
        {
            for (int i = 0; i < 3; i++)
            {
                if (i == 0)
                    out << "NUMBER    ";
                else if (i == 1)
                    out << "DATA      ";
                else
                    out << "TIME      ";
            }
        }

        out << '\n';

        for (int i = 0; i < splitNumber; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                if (splitTable[i][j].getNumber() == 0)
                {
                    out << makeDefLength(" ", 30);
                    break;
                }

                dataToWrite = makeDefLength(std::to_string(splitTable[i][j].getNumber()), 8);

                out << dataToWrite << "  ";

                dataToWrite = makeDefLength(std::to_string(splitTable[i][j].getData()), 8);

                out << dataToWrite << "  ";

                dataToWrite = makeDefLength(std::to_string(splitTable[i][j].getTime()), 8);

                out << dataToWrite << "  ";

            }
            out << "\n";
        }
        out << "\n";
    }
    else
        exit(1);

    out.close();
}



int main()
{
    std::ifstream fileBuffer("buffer.txt");

    if (!fileBuffer)
    {
        std::cerr << "Can't open buffer file" << std::endl;
        exit(1);
    }

    double threshold = 0;
    std::string outputFileName = "";
    std::string stringToConvert = "";
    std::string openFile;
    std::string nameCol = "";
    int splitNumer = 0;
    int isAdvansed = 0;
    int isAdditional = 0;

    //считываем данные из окна Threshold fragmentation
    getline(fileBuffer, openFile);

    getline(fileBuffer, stringToConvert);
    threshold = std::stod(stringToConvert);

    getline(fileBuffer, stringToConvert);
    outputFileName = stringToConvert;

    getline(fileBuffer, stringToConvert);
    isAdditional = std::stoi(stringToConvert);

    getline(fileBuffer, stringToConvert);
    splitNumer = std::stoi(stringToConvert);

    getline(fileBuffer, stringToConvert);
    nameCol = stringToConvert;

    getline(fileBuffer, stringToConvert);
    isAdvansed = std::stoi(stringToConvert);

    fileBuffer.close();

    std::vector<Measurement> column = readColumn(openFile);

    column = makeFragment(column, threshold);

    splitData(column, nameCol, "fragment.txt", isAdditional, splitNumer, isAdvansed);

    return 0;
}

