g++ -std=c++17 -O2 -Wall -Wextra c.cpp -o c
g++ -std=c++17 -O2 -Wall -Wextra w.cpp -o w
g++ -std=c++17 -O2 -Wall -Wextra g.cpp -o g

for((i = 1; ; ++i)); do
    ./g $i > randomInput
    ./w <randomInput > WA
    ./c <randomInput > AC
    diff -w WA AC || break
    echo "Passed test: "  $i
done

echo -e "\nWA on the following test:"
cat randomInput
echo "Your answer is:"
cat WA
echo "Correct answer is:"
cat AC