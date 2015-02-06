echo "1000 elements"
echo "============="

time ./../build/tp-heritage < 1000.in > /dev/null
echo ""
echo ""

echo "10000 elements"
echo "=============="

time ./../build/tp-heritage < 10000.in > /dev/null
echo ""
echo ""

echo "100000 elements"
echo "==============="

time ./../build/tp-heritage < 100000.in > /dev/null
echo ""
echo ""

echo "1000000 elements"
echo "================"

time ./../build/tp-heritage < 1000000.in > /dev/null
