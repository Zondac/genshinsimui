/* rand example: guess the number */
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <vector>
#include <iostream>
#include <numeric>

float avgFirstGET(std::vector<std::vector<int>> lst)
{
    int val = 0;
    for (int articles = 0; articles < lst.size(); articles++)
    {
        val += lst[articles][0];
    }
    return (float(val) / lst.size());
}

int constellations(std::vector<std::vector<int>> nestlst, int constellation_to_find)
{
    int val = 0;
    for (int x = 0; x < nestlst.size(); x++)
    {
        if (nestlst[x].size() > constellation_to_find)
        {
            val++;
        }
    }

    return val;
}

void printVector(std::vector<int> lst)
{
    for (int x = 0; x < lst.size(); x++)
    {
        if (x + 1 < lst.size())
        {
            std::cout << lst[x] << ", ";
        }
        else
        {

            std::cout << lst[x] << ".\n";
        }
    }
}

int main()
{
    while (true) {
    int rng, savedwishes, pitybonus = 0, fivestarpity = 0, fiftyfifty, attempts = 200000, pitydefault, sum_of_elems = 0, sum_of_elemsB = 0;

    bool guaranteednext = false, guaranteednextdefault = false;

    std::vector<int> fivestar, wrongfive, simarraylen, simarrayblen;

    std::vector<std::vector<int>> simarrayB, simarray;

    printf("How many wishes do you have saved up?\n");
    std::cin >> savedwishes;
    /*printf ("How many times do we run the simulation? (Higher = more accurate, more time spent. Recommended default is 100000) \n");
    scanf ("%d",&attempts);*/
    printf("What's your pity at? (Just write 0 if you don't know or don't want pity included in the calculations)\n");

    std::cin >> pitydefault;

    printf("Did you lose 50/50 last time? (1 for yes, 0 for no)\n");
    std::cin >> guaranteednextdefault;


    printf("How many times should the simulation run? (Higher = More accurate, but more processing time. 100,000 should be enough)\n");
    std::cin >> attempts;
    /* initialize random seed: */
    srand(time(NULL));

    
        for (int sim = 0; sim < attempts; sim++)
        {

            fivestar.clear();
            wrongfive.clear();
            fivestarpity = pitydefault;
            pitybonus = 0;
            guaranteednext = guaranteednextdefault;
            for (int wishes = 0; wishes < savedwishes; wishes++)
            {

                rng = rand() % 1000;

                if (rng <= 6 + pitybonus)
                {
                    fiftyfifty = rand() % 2;
                    if (fiftyfifty == 1 || guaranteednext)
                    {
                        fivestar.push_back(wishes);
                        pitybonus = 0;
                        fivestarpity = 0;
                        guaranteednext = false;
                    }
                    else
                    {
                        wrongfive.push_back(wishes);
                        guaranteednext = true;
                        pitybonus = 0;
                        fivestarpity = 0;
                    }
                }
                else
                    fivestarpity++;

                if (fivestarpity >= 73)
                {
                    pitybonus += 60;
                }
            }

            if (!fivestar.empty())
            {
                simarrayB.push_back(fivestar);
                simarrayblen.push_back(fivestar.size());
            }
            if (!wrongfive.empty())
            {
                simarray.push_back(wrongfive);
                simarraylen.push_back(wrongfive.size());
            }
        }

        std::cout << "You have a " << (float(constellations(simarrayB, 0)) / attempts) * 100 << "% chance of getting C0, or " << constellations(simarrayB, 0) << ":" << attempts <<"\n";
        std::cout << "You have a " << (float(constellations(simarrayB, 1)) / attempts) * 100 << "% chance of getting C1, or " << constellations(simarrayB, 1) << ":" << attempts << "\n";
        std::cout << "You have a " << (float(constellations(simarrayB, 2)) / attempts) * 100 << "% chance of getting C2, or " << constellations(simarrayB, 2) << ":" << attempts << "\n";
        std::cout << "You have a " << (float(constellations(simarrayB, 3)) / attempts) * 100 << "% chance of getting C3, or " << constellations(simarrayB, 3) << ":" << attempts << "\n";
        std::cout << "You have a " << (float(constellations(simarrayB, 4)) / attempts) * 100 << "% chance of getting C4, or " << constellations(simarrayB, 4) << ":" << attempts << "\n";
        std::cout << "You have a " << (float(constellations(simarrayB, 5)) / attempts) * 100 << "% chance of getting C5, or " << constellations(simarrayB, 5) << ":" << attempts << "\n";
        std::cout << "You have a " << (float(constellations(simarrayB, 6)) / attempts) * 100 << "% chance of getting C6, or " << constellations(simarrayB, 6) << ":" << attempts << "\n";

        std::cout << "Out of simulated rolls that actually got the desired characters, the average rolls before getting the desired character was " << avgFirstGET(simarrayB) << "\n";

        for (std::vector<int>::iterator it = simarrayblen.begin(); it != simarrayblen.end(); ++it) sum_of_elemsB += *it;
        for (std::vector<int>::iterator it = simarraylen.begin(); it != simarraylen.end(); ++it) sum_of_elems += *it;

        std::cout << "For every non-banner character dropped, " << (float(sum_of_elemsB)/sum_of_elems) << " banner characters dropped\n";
       
        }
}