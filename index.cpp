#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
stack<int>label;
string str;
int Calculate ( float a )
{
	return ( ( int ) ( a * 10 + 5 ) ) / 10;
}
void Setpos ( float x, float y )
{
	COORD pos;
	pos.X = Calculate ( y * 4 ) / 2;
	pos.Y = Calculate ( x );
	SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), pos );
}
void print ( int n )
{
	string str_;
	
	switch ( n )
	{
		case 1:
			cout << "Color RGB:";
			cin >> str_;
			break;
			
		case 5:
			cout << "Experiment ID:";
			cin >> str_;
			break;
			
		case 6:
			cout << "Discussion ID:";
			cin >> str_;
			break;
			
		case 7:
			cout << "User ID:";
			cin >> str_;
			break;
			
		default:
			break;
	}
	
	str += "=";
	str += str_;
	str += ">";
}
bool REPLACE_COLOR_WITH_A;
void settings()
{
	while ( true )
	{
		system ( "cls" );
		cout << "Settings\n\n\n";
		cout << "Use W/S to move,tab to revise.\n";
		cout << boolalpha;
		cout << "Use </a> to replace </color>\t\t" << REPLACE_COLOR_WITH_A << endl;
		int pos = 1;
		Setpos ( 3 + pos, 30 );
		cout << "*";
		char ch = getch();
		ch = tolower ( ch );
		
		if ( pos < 2 && ch == 's' )
			pos++;
			
		else if ( pos > 0 && ch == 'w' )
			pos--;
	}
}
int main()
{
	while ( true )
	{
		cout << "Physics Lab RichText Generator\n\n\n";
		cout << "0.Compelete All Label 1.<color> 2.<a> 3.<b> 4.<i> 5.<experiment> 6.<discussion> 7.<user> 8.</> 9.Settings\n";
		cout << "Current RichText:" << str << "\n";
		int a;
		a = ( int ) ( getch() - '0' );
		
		if ( a == 0 )
		{
			while ( !label.empty() )
			{
				switch ( label.top() )
				{
					case 1:
						if ( REPLACE_COLOR_WITH_A )
							str += "</a>";
							
						else
							str += "</color>";
							
						break;
						
					case 2:
						str += "</a>";
						break;
						
					case 3:
						str += "</b>";
						break;
						
					case 4:
						str += "</i>";
						break;
						
					case 5:
						str += "</experiment>";
						break;
						
					case 6:
						str += "</discussion>";
						break;
						
					case 7:
						str += "</user>";
						break;
						
					default:
						break;
				}
				
				label.pop();
			}
		}
		
		else if ( a == 9 )
			settings();
			
		else if ( a != 8 )
		{
			label.push ( a );
			
			switch ( a )
			{
				case 1:
					str += "<color";
					print ( a );
					break;
					
				case 2:
					str += "<a>";
					break;
					
				case 3:
					str += "<b>";
					break;
					
				case 4:
					str += "<i>";
					break;
					
				case 5:
					str += "<experiment";
					print ( a );
					break;
					
				case 6:
					str += "<discussion";
					print ( a );
					break;
					
				case 7:
					str += "<user";
					print ( a );
					break;
					
				default:
					break;
			}
		}
		
		else if ( a == 8 )
		{
			switch ( label.top() )
			{
				case 1:
					if ( REPLACE_COLOR_WITH_A )
						str += "</a>";
						
					else
						str += "</color>";
						
					break;
					
				case 2:
					str += "</a>";
					break;
					
				case 3:
					str += "</b>";
					break;
					
				case 4:
					str += "</i>";
					break;
					
				case 5:
					str += "</experiment>";
					break;
					
				case 6:
					str += "</discussion>";
					break;
					
				case 7:
					str += "</user>";
					break;
					
				default:
					break;
			}
			
			label.pop();
		}
		
		system ( "cls" );
	}
	
	return 0;
}
