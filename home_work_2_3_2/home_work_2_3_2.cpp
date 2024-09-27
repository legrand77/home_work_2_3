#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <cstdlib>

struct adress
{
private:
    std::string name_city;
    std::string street_name;
    int house_number{};
    int apartment_number{};
public:
    void setAdressname_city(std::string name_city)
    {
        this->name_city = name_city;
    };
    void setAdressstreet_name(std::string street_name)
    {
        this->street_name = street_name;
    };
    void setAdresshouse_number(int house_number)
    {
        this->house_number = house_number;
    };
    void setAdressapartment_number(int apartment_number)
    {
        this->apartment_number = apartment_number;
    };
    std::string getAdressname_city()
    {
        return name_city;
    };
    std::string getAdressstreet_name()
    {
        return street_name;
    };
    int getAdresshouse_number()
    {
        return house_number;
    };
    int getAdressapartment_number()
    {
        return apartment_number;
    };

};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int N;
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (!fin.is_open())
    {
        std::cout << "Не получилось открыть файл in.txt" << std::endl;
        return 1;
    }
    if (!fout.is_open())
    {
        std::cout << "Не получилось открыть файл out.txt" << std::endl;
        return 1;
    }
    fin >> N;
    adress* house = new adress[N];
    std::string name_city_1;
    std::string street_name_1;
    int house_number_1;
    int apartment_number_1;
    for (int i = 0; i < N; i++)
    {
        fin >> name_city_1;
        house[i].setAdressname_city(name_city_1);
        fin >> street_name_1;
        house[i].setAdressstreet_name(street_name_1);
        fin >> house_number_1;
        house[i].setAdresshouse_number(house_number_1);
        fin >> apartment_number_1;
        house[i].setAdressapartment_number(apartment_number_1);
    }
    bool swapped = false;

    do
    {
        swapped = false;
        for (int i = 1; i < N; i++)
        {
            if (house[i].getAdressname_city().compare(house[i-1].getAdressname_city()) == -1)
            {
                std::string temp = house[i - 1].getAdressname_city();
                std::string temp_1 = house[i - 1].getAdressstreet_name();
                int temp_2 = house[i - 1].getAdresshouse_number();
                int temp_3 = house[i - 1].getAdressapartment_number();
                house[i-1].setAdressname_city(house[i].getAdressname_city());
                house[i-1].setAdressstreet_name(house[i].getAdressstreet_name());
                house[i-1].setAdresshouse_number(house[i].getAdresshouse_number());
                house[i-1].setAdressapartment_number(house[i].getAdressapartment_number());
                house[i].setAdressname_city(temp);
                house[i].setAdressstreet_name(temp_1);
                house[i].setAdresshouse_number(temp_2);
                house[i].setAdressapartment_number(temp_3);
                swapped = true;
            }
        }
    } while (swapped);

    fout << N;
    fout << std::endl;
    for (int i = 0; i < N; i++)
    {
        fout << house[i].getAdressname_city();
        fout << ", ";
        fout << house[i].getAdressstreet_name();
        fout << ", ";
        fout << house[i].getAdresshouse_number();
        fout << ", ";
        fout << house[i].getAdressapartment_number();
        fout << std::endl;
    }
    delete[] house;
    fin.close();
    fout.close();
}