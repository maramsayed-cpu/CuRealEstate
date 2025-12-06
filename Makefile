objects = main.o Control.o View.o CuRealEstate.o Filter.o Listing.o Price.o PropertyType.o Price_Filter.o Type_Filter.o PriceAndType_Filter.o
testobjects = test.o Tester.o TestControl.o View.o CuRealEstate.o Filter.o Listing.o Price.o PropertyType.o Price_Filter.o Type_Filter.o PriceAndType_Filter.o

a4: $(objects)
	g++ -o a4 $(objects)

a4test: $(testobjects)
	g++ -o a4test $(testobjects)

main.o: main.cc CuRealEstate.h
	g++ -c main.cc

test.o: test.cc
	g++ -c test.cc

Control.o: Control.h Control.cc CuRealEstate.h Price_Filter.h Type_Filter.h PriceAndType_Filter.h
	g++ -c Control.cc

TestControl.o: TestControl.cc TestControl.h Price_Filter.h Type_Filter.h PriceAndType_Filter.h
	g++ -c TestControl.cc

View.o: View.h View.cc
	g++ -c View.cc

CuRealEstate.o: CuRealEstate.h CuRealEstate.cc List.h
	g++ -c CuRealEstate.cc

Listing.o: Listing.h Listing.cc Price.h PropertyType.h
	g++ -c Listing.cc

Filter.o: Filter.h Filter.cc Listing.h
	g++ -c Filter.cc

Type_Filter.o: Type_Filter.h Type_Filter.cc PropertyType.h Filter.h
	g++ -c Type_Filter.cc

Price_Filter.o: Price_Filter.h Price_Filter.cc Price.h Filter.h
	g++ -c Price_Filter.cc

PriceAndType_Filter.o: PriceAndType_Filter.h PriceAndType_Filter.cc Price_Filter.h Type_Filter.h Price.h Filter.h
	g++ -c PriceAndType_Filter.cc

Price.o: Price.h Price.cc
	g++ -c Price.cc

Tester.o: Tester.h Tester.cc
	g++ -c Tester.cc

PropertyType.o: PropertyType.h PropertyType.cc
	g++ -c PropertyType.cc

clean:
	rm a4 a4test *.o