#include<stdio.h>
#include<math.h>

typedef struct {
	double sumUp, sumDown, checkPoint;
}Calculate;

Calculate calSum();

int main()
{
	double area;
	Calculate p = calSum();	
	if (p.checkPoint == 1)
	{
		printf("\nIt's a point, not a polygonal pattern.\n\n");
	}
	else if(p.checkPoint == 0)
	{
		area = fabs(0.5 * (p.sumDown - p.sumUp));
		printf("\nPolygon Area is : %.2f unit^2\n\n", area);
	}
	else if(p.checkPoint == 2)
	{
		printf("\nIt's a Straight line, not a polygonal pattern.\n\n");
	}
	else {}
	

	return 0;
}

Calculate calSum()
{
	Calculate p{};
	p.checkPoint = 0;
	p.sumDown = 0;
	p.sumUp = 0;
	int x[1000] = { 0 }, y[1000] = { 0 };
	int sides = 0;
	printf("Enter the number of sides of the polygon : ");
	scanf_s("%d", &sides);

	if (sides>2)
	{
		p.checkPoint = 0;
		printf("\nEnter Coordinates of the polygon point\nFollow this example\n");
		printf("1 1\n2 2\n3 3\n4 4\n");
		printf("\nEnter your Coordinates\n");


		for (int i = 0; i < sides; i++)		//Input
		{
			scanf_s("%d %d", &x[i], &y[i]);
			getchar();
		}

		x[sides] = x[0];	// Add Coordinate
		y[sides] = y[0];

		for (int i = 0; i < sides; i++)		//CheckPoint
		{
			if (x[i] == x[i + 1] && y[i] == y[i + 1])
			{
				p.checkPoint = 1;
			}
		}

		for (int i = 0; i < sides; i++)
		{
			p.sumDown += x[i] * y[i + 1];	// MultipleDown
			p.sumUp += y[i] * x[i + 1];		// MultipleUp
		}

		return p;
	}
	else if (sides == 1)
	{
		p.checkPoint = 1;
		return p;

	}
	else if (sides == 2)
	{
		p.checkPoint = 2;
		return p;
	}
	else
	{
		printf("\n\nError Please Try Again.\n\n");
		p.checkPoint = 3;
		return p;
	}
	

}



