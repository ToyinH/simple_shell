#include <stdio.h>
int custom_strcmp(const char *s1, const char *s2);
int main(void)
{
	    char *str1 = "Name";
	        char *str2 = "Bame";

		    if (custom_strcmp(str1, str2) == 0)
			        {
					        printf("%s and %s are thesame string\n", str1, str2);
						        printf("%d\n", custom_strcmp(str1, str2));
							    }
		        else
				    {
					            printf("%s and %s are not thesame\n", str1, str2);

						            printf("%d\n", custom_strcmp(str1, str2));
							        }
			    return 0;
}
