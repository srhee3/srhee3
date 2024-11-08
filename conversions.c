#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>

void convert_temperature();
void convert_distance();

int main(void)
{
    char unit_of_measurement;
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    scanf("%c", &unit_of_measurement);
    
    if(unit_of_measurement == 'T' || unit_of_measurement == 't') {
        convert_temperature();
    }
    else if (unit_of_measurement == 'D' || unit_of_measurement == 'd') {
        convert_distance();
    }

    else if ('J')
    printf("Unknown conversion %c chosen. Ending program." , unit_of_measurement);
    
    else {
    printf("Invalid formatting. Ending program.");
    }
    return 0;
}

//defining temperature_function
void convert_temperature()
{ 
    double degree, new_degree, temperature; 
    char suffix, new_suffix;

    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    scanf("%lf %c", &degree, &suffix);
    printf("Enter the new unit type (F, C, or K): ");
    scanf(" %c", &new_suffix);
    
    temperature = degree; 
    
    if (suffix == 'F' || suffix == 'f'); {
        temperature = (degree - 32) * 5/9;
    }
    
    if (suffix == 'K' || suffix == 'k') { 
        temperature = degree-273.15;
  }
    else if (suffix != 'C' && suffix != 'c')  { 
    printf("%c is not a valid temperature type. Ending program.", suffix);
    exit(0);
  }
  
  //conversion
  if (new_suffix == 'F' || new_suffix == 'f')  { 
      new_degree = (temperature * 9/5) +32;
  }
  
  else if (new_suffix == 'C' || new_suffix == 'c') 
  {   new_degree = temperature;
  
  }

   if (new_suffix == 'K' || new_suffix == 'k') { 
      new_degree =temperature + 273.15;
  }

   else ("c"); 
      printf("%c is not a valid temperature type. Ending program.", new_suffix);
      exit(0);
  
   
  printf("%.2lf%c is %.2lf%c", degree, toupper(suffix), new_degree, toupper(new_suffix));

}
  
//defining distance
void convert_distance()
{
    double measurement, new_measurement, distance;
    char suffix, new_suffix;
    
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    scanf("%lf %c", &measurement, &suffix);  
    
    printf("Enter the new unit type (I,F,Y,M): ");
    scanf(" %c", &new_suffix); 
    
    distance = measurement;
    if (suffix == 'I' || suffix == 'i') {
        distance = (measurement / 36);
    }
    
    if (suffix == 'M' || suffix == 'm') {
        distance = (measurement / 63360);
    }
    
    else if (suffix != 'Y' && suffix != 'y') { 
        printf("%c is not a valid distance type. Ending program.", suffix);
    
    exit(0);  
  }
  
    if (new_suffix == 'I' || new_suffix == 'i') { 
        new_measurement = distance * 36;
  }
  
    else if(new_suffix == 'F' || new_suffix == 'f') { 
        new_measurement = (distance * 3);
  }

    else if (new_suffix == 'Y' || new_suffix == 'y') { 
      new_measurement = distance;
  }

    else if (new_suffix == 'M' || new_suffix == 'm') { 
      new_measurement = (distance / 1760);
  }

  else  
  { printf("%c is not a valid temperature type. Ending program.", new_suffix);
    exit(0);
  }
  
  printf("%.2lf%c is %.2lf%c", measurement, toupper(suffix), new_measurement, toupper(new_suffix));
}

    

