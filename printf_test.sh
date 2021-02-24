git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
make re
./test
read -s
cd ..
rm -rf pft_2019

git clone https://github.com/AntoineBourin/printf-tester.git
cp libftprintf.a printf-tester
cd printf-tester
sh test.sh
read -s
cd ..
rm -rf printf-tester

git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF
sh runtest.sh
read -s
cd ..
rm -rf 42TESTERS-PRINTF


git clone https://github.com/Kwevan/PRINTF_TESTER.git PRINTF_TESTER_test
git clone https://github.com/charMstr/printf_lover_v2.git printf_lover_v2_test

