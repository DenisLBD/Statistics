#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>


//фукция вычисления среднего значения
double getMean(std::vector<std::string>& column)
{
    double mean = 0;
    double sum = 0;
    for (int i = 0; i < column.size(); i++)
    {
        sum += std::stod(column[i]);
    }

    mean = sum / column.size();

    return mean;
}

//функция вычисления максимального значения
double getMax(std::vector<std::string>& column)
{
    double max = 0;

    if (column.size() > 1)
        max = std::max(std::stod(column[0]), std::stod(column[1]));
    else if (column.size() == 1)
    {
        max = std::stod(column[0]);
        return max;
    }
    else 
    {
        std::cerr << "More arguments!\n";
        exit(1);
    }

    for (int i = 2; i < column.size(); i++)
    {
        max = std::max(max, std::stod(column[i]));
    }

    return max;
}

//функция вычисления минимального значения
double getMin(std::vector<std::string>& column)
{
    double min = INT16_MAX;

    if (column.size() > 1)
        min = std::min(std::stod(column[0]), std::stod(column[1]));
    else if (column.size() == 1)
    {
        min = std::stod(column[0]);
        return min;
    }
    else
    {
        std::cerr << "More arguments!\n";
        exit(1);
    }

    for (int i = 2; i < column.size(); i++)
    {
        min = std::min(min, std::stod(column[i]));
    }

    return min;
}

//функция вычисления СКО
double getStdErr(std::vector<std::string>& column)
{
    double sko = 0;
    double sum = 0;
    double mean = getMean(column);

    for (int i = 0; i < column.size(); i++)
    {
        sum = sum + (std::stod(column[i]) - mean) * (std::stod(column[i]) - mean);
    }

    sum = sum / column.size();
    sko = sqrt(sum);

    return sko;
}

//функция вычисления коэффициентов a и b
std::pair<double, double> getCoeff(std::vector<std::string>& column, std::vector<std::string>& timeCol)
{  
    std::pair<double, double> AandB = { 0, 0 };
    double a = 0;
    double b = 0;
    double sumx = 0;
    double sumy = 0;
    double sumx2 = 0;
    double sumxy = 0;

    if (column.size() < 2)
        return AandB;

    for (int i = 0; i < column.size(); i++)
    {
        sumx += std::stod(timeCol[i]);
        sumy += std::stod(column[i]);
        sumx2 += std::stod(timeCol[i]) * std::stod(timeCol[i]);
        sumxy += std::stod(column[i]) * std::stod(timeCol[i]);
    }

    a = (column.size() * sumxy - (sumx * sumy)) / (column.size() * sumx2 - sumx * sumx);
    b = (sumy - a * sumx) / column.size();

    AandB.first = a;
    AandB.second = b;

    return AandB;
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

//функция чтения фрагмента
std::vector<std::string> readColumn(std::string fileName)
{
    std::vector<std::string> column;
    std::ifstream fileData(fileName);

    if (!fileData)
    {
        std::cerr << "Can't open data file" << std::endl;
        exit(1);
    }

    std::string firstLine = "";
    std::string line = "";

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

        column.push_back(line);
        std::cout << line << std::endl;
    }

    fileData.close();
    return column;
}

//функция выделения фрагмента с определенным порогом
std::vector<std::string> makeFragment(std::vector<std::string>& sourceData, double threshold)
{
    std::vector<std::string> fragment;

    int i = 0;

    while (i < sourceData.size())
    {
        if (std::stod(sourceData[i]) > threshold)
        {
            fragment.push_back(sourceData[i]);
        }
        i++;
    }
    return fragment;
}

//функция вычисления значений времени
std::vector<std::string> getTimeCol(int size)
{
    std::vector<std::string> timeCol;
    double time = 0.25;

    for (int i = 0; i < size; i++)
    {
        timeCol.push_back(std::to_string(time));
        time += 0.25;
    }

    return timeCol;
}

//функция разделения фрагмента на подфрагменты
std::vector<std::string> makeSubFragm(std::vector<std::string>& data, int initPos, int subLength)
{
    std::vector<std::string> subfragment;

    for (int i = 0; i < subLength; i++)
    {
        if (i + initPos == data.size())
            return subfragment;

        subfragment.push_back(data[i + initPos]);
    }

    return subfragment;
}

//функция построения таблицы
void makeTable(std::vector<std::string>& data, std::vector<std::string>& time, std::string nameCol, int statistica, int isAdditional, int subLength)
{
    if (isAdditional == 0)
        subLength = data.size();

    std::ofstream out("subfragm.txt", std::ios::out);

    if (!out)
    {
        std::cerr << "Can't save information in file";
        exit(1);
    }

    //число рядов элементов
    int numCol = ceil((data.size() * 1.0) / subLength);

    std::string dataToWrite = "";

    if (isAdditional == 0)
    {
        nameCol = makeDefLength(nameCol, 10);
        out << nameCol;

        //MEAN
        if ((statistica & 1) == 1)
        {
            out << makeDefLength(std::to_string(getMean(data)), 8) << "  ";
        }

        //MIN
        if ((statistica & 2) == 2)
        {
            out << makeDefLength(std::to_string(getMin(data)), 8) << "  ";
        }

        //MAX
        if ((statistica & 4) == 4)
        {
            out << makeDefLength(std::to_string(getMax(data)), 8) << "  ";
        }

        //SKO
        if ((statistica & 8) == 8)
        {
            out << makeDefLength(std::to_string(getStdErr(data)), 8) << "  ";
        }

        //Linear
        if ((statistica & 16) == 16)
        {
            out << makeDefLength(std::to_string(getCoeff(data, time).first), 8) << "  ";

            out << makeDefLength(std::to_string(getCoeff(data, time).second), 8) << "  ";
        }
    }
    else if (isAdditional == 1)
    {
        //для additional fragmentation
        nameCol.push_back('_');

        std::string tmp = "";
        int k = 0;//счетчик элементов data
        std::vector<std::string> subfragment;
        std::vector<std::string> timeFragment;

        for (int i = 0; i < numCol; i++) //названия подстолбцов
        {
            tmp = nameCol;
            tmp += char(i + 65);
            tmp = makeDefLength(tmp, 10);

            out << tmp;

            subfragment = makeSubFragm(data, i * subLength, subLength);
            timeFragment = makeSubFragm(time, i * subLength, subLength);

            //MEAN
            if ((statistica & 1) == 1)
            {
                out << makeDefLength(std::to_string(getMean(subfragment)), 8) << "  ";
            }

            //MIN
            if ((statistica & 2) == 2)
            {
                out << makeDefLength(std::to_string(getMin(subfragment)), 8) << "  ";
            }

            //MAX
            if ((statistica & 4) == 4)
            {
                out << makeDefLength(std::to_string(getMax(subfragment)), 8) << "  ";
            }

            //SKO
            if ((statistica & 8) == 8)
            {
                out << makeDefLength(std::to_string(getStdErr(subfragment)), 8) << "  ";
            }

            //Linear
            if ((statistica & 16) == 16)
            {
                out << makeDefLength(std::to_string(getCoeff(subfragment, timeFragment).first), 8) << "  ";

                out << makeDefLength(std::to_string(getCoeff(subfragment, timeFragment).second), 8) << "  ";
            }

            out << '\n';
        }
    }
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
    std::string openFile = "";
    std::string nameCol = "";
    std::string stringToConvert = "";
    int splitNumber = 0;
    int isAdditional = 0;
    int statistica = 0;

    getline(fileBuffer, stringToConvert);
    getline(fileBuffer, stringToConvert);

    //считываем данные из окна fragmentation statistics
    getline(fileBuffer, stringToConvert);
    statistica = std::stoi(stringToConvert);

    getline(fileBuffer, stringToConvert);
    nameCol = stringToConvert;

    getline(fileBuffer, stringToConvert);
    openFile = stringToConvert;

    getline(fileBuffer, stringToConvert);
    threshold = std::stod(stringToConvert);

    getline(fileBuffer, stringToConvert);
    splitNumber = std::stoi(stringToConvert);

    getline(fileBuffer, stringToConvert);
    isAdditional = std::stoi(stringToConvert);

    fileBuffer.close();

    std::vector<std::string> column = readColumn("Safe.txt");

    std::vector<std::string> timeCol = getTimeCol(column.size());

    std::ofstream out("fragment.txt", std::ios::out);

    if (!out)
    {
        std::cerr << "Can't save information in file";
        exit(1);
    }

    out << makeDefLength("NAME", 10);

    //MEAN
    if ((statistica & 1) == 1)
    {
        out << makeDefLength("Mean", 10);
    }

    //MIN
    if ((statistica & 2) == 2)
    {
        out << makeDefLength("Min", 10);
    }

    //MAX
    if ((statistica & 4) == 4)
    {
        out << makeDefLength("Max", 10);
    }

    //SKO
    if ((statistica & 8) == 8)
    {
        out << makeDefLength("Std.Err.", 10);
    }

    //Linear
    if ((statistica & 16) == 16)
    {
        out << makeDefLength("a", 10);

        out << makeDefLength("b", 10);
    }

    out.close();

    makeTable(column, timeCol, nameCol, statistica, isAdditional, splitNumber);

    return 0;
}