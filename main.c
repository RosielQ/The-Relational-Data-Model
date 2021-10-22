//
//  main.c
//  Project4
//
//  Created by 魏芊芊 on 4/15/21.
//

#include "SNAP.h"
//#include "CP.h"
//#include "CDH.h"
//#include "CSG.h"

int main(int argc, const char * argv[]) {
    
    /*--------------------StudentId-Name-Address-Phone Demonstration--------------------*/
    printf("StudentId-Name-Address-Phone Demonstration\n");

    new_HashArray_SNAP();
    printf("\n");

    printf("insert_SNAP(12345, \"C. Brown\", \"12 Apple St.\", \"555-1234\");\n");
    insert_SNAP(12345, "C. Brown", "12 Apple St.", "555-1234");
    print_relation_SNAP();
    printf("\n");

    printf("insert_SNAP(67890, \"L. Van Pelt\", \"34 Pear Ave.\", \"555-5678\");\n");
    insert_SNAP(67890, "L. Van Pelt", "34 Pear Ave.", "555-5678");
    print_relation_SNAP();
    printf("\n");

    printf("insert_SNAP(22222, \"P. Patty\", \"56 Grape Blvd.\", \"555-9999\");\n");
    insert_SNAP(22222, "P. Patty", "56 Grape Blvd.", "555-9999");
    print_relation_SNAP();
    printf("\n");

    printf("insert_SNAP(33333, \"C. Joseph\", \"500 Wilson Blvd.\", \"123-4567\");\n");
    insert_SNAP(33333, "C. Joseph", "500 Wilson Blvd.", "123-4567");
    print_relation_SNAP();
    printf("\n");

    printf("insert_SNAP(33333, \"C. Joseph\", \"500 Wilson Blvd.\", \"123-4567\");\n");
    insert_SNAP(33333, "C. Joseph", "500 Wilson Blvd.", "123-4567");
    print_relation_SNAP();
    printf("\n");

    printf("insert_SNAP(44444, \"C. Joseph\", \"10 abc street.\", \"000-0000\");\n");
    insert_SNAP(44444, "C. Joseph", "10 abc street.", "000-0000");
    print_relation_SNAP();
    printf("\n");

    printf("lookup_name_SNAP(\"C. Joseph\");\n");
    lookup_name_SNAP("C. Joseph");
    print_relation_SNAP();
    printf("\n");

    printf("delete_SNAP(12345, \"C. Brown\", \"12 Apple St.\", \"555-1234\");\n");
    delete_SNAP(12345, "C. Brown", "12 Apple St.", "555-1234");
    print_relation_SNAP();
    printf("\n");

    printf("delete_SNAP(12345, \"C. Brown\", \"12 Apple St.\", \"555-1234\");\n");
    delete_SNAP(12345, "C. Brown", "12 Apple St.", "555-1234");
    print_relation_SNAP();
    printf("\n");

    printf("delete_SNAP(67890, \"*\", \"*\", \"*\");\n");
    delete_SNAP(67890, "*", "*", "*");
    print_relation_SNAP();
    printf("\n");

    printf("lookup_SNAP(22222, \"P. Patty\", \"56 Grape Blvd.\", \"555-9999\");\n");
    lookup_SNAP(22222, "P. Patty", "56 Grape Blvd.", "555-9999");
    print_relation_SNAP();
    printf("\n");

    printf("lookup_SNAP(33333, \"*\", \"*\", \"*\");\n");
    lookup_SNAP(33333, "*", "*.", "*");
    print_relation_SNAP();
    printf("\n");

    printf("lookup_SNAP(110, \"*\", \"*\", \"*\");\n");
    lookup_SNAP(110, "*", "*.", "*");
    print_relation_SNAP();
    printf("\n");
    
    
    
    
    
//    /*--------------------Course-Prerequisite Demonstration--------------------*/
//
//    //Populate the table
//    printf("\n");
//
//    printf("Course-Prerequisite Demonstration\n");
//
//    new_HashArray_CP();
//    printf("\n");
//
//    printf("insert_CP(\"CS101\", \"CS100\");\n");
//    insert_CP("CS101", "CS100");
//    print_relation_CP();
//    printf("\n");
//
//    printf("insert_CP(\"EE200\", \"EE005\");\n");
//    insert_CP("EE200", "EE005");
//    print_relation_CP();
//    printf("\n");
//
//    printf("insert_CP(\"EE200\", \"CS100\");\n");
//    insert_CP("EE200", "CS100");
//    print_relation_CP();
//    printf("\n");
//
//    printf("insert_CP(\"CS120\", \"CS101\");\n");
//    insert_CP("CS120", "CS101");
//    print_relation_CP();
//    printf("\n");
//
//    printf("insert_CP(\"CS121\", \"CS120\");\n");
//    insert_CP("CS121", "CS120");
//    print_relation_CP();
//    printf("\n");
//
//    printf("insert_CP(\"CS205\", \"CS101\");\n");
//    insert_CP("CS205", "CS101");
//    print_relation_CP();
//    printf("\n");
//
//    printf("insert_CP(\"CS206\", \"CS121\");\n");
//    insert_CP("CS206", "CS121");
//    print_relation_CP();
//    printf("\n");
//
//    printf("insert_CP(\"CS206\", \"CS205\");\n");
//    insert_CP("CS206", "CS205");
//    print_relation_CP();
//    printf("\n");
//
//
//    //other instructions
//    printf("insert_CP(\"EE200\", \"EE005\");\n");
//    insert_CP("EE200", "EE005");
//    print_relation_CP();
//    printf("\n");
//
//    printf("delete_CP(\"CS205\", \"CS101\");\n");
//    delete_CP("CS205", "CS101");
//    print_relation_CP();
//    printf("\n");
//
//    printf("delete_CP(\"CS205\", \"CS101\");\n");
//    delete_CP("CS205", "CS101");
//    print_relation_CP();
//    printf("\n");
//
//    printf("delete_CP(\"EE200\", \"*\");\n");
//    delete_CP("EE200", "*");
//    print_relation_CP();
//    printf("\n");
//
//    printf("delete_CP(\"AB123\", \"*\");\n");
//    delete_CP("AB123", "*");
//    print_relation_CP();
//    printf("\n");
//
//    printf("lookup_CP(\"CS205\", \"CS101\");\n");
//    lookup_CP("CS205", "CS101");
//    print_relation_CP();
//    printf("\n");
//
//    printf("lookup_CP(\"CS206\", \"*\");\n");
//    lookup_CP("CS206", "*");
//    print_relation_CP();
//    printf("\n");
//
//    printf("lookup_CP(\"EE200\", \"*\");\n");
//    lookup_CP("EE200", "*");
//    print_relation_CP();
//    printf("\n");
//
//
//    printf("lookup_CP(\"AB123\", \"*\");\n");
//    lookup_CP("AB123", "*");
//    print_relation_CP();
//    printf("\n");

    
    
//    /*--------------------Course-Day-Hour Demonstration--------------------*/
//
//    //Populate the table
//    printf("\n");
//
//    printf("Course-Day-Hour Demonstration\n");
//
//    new_HashArray_CDH();
//    printf("\n");
//
//    printf("insert_CDH(\"CS101\", \"M\", \"9AM\");\n");
//    insert_CDH("CS101", "M", "9AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("insert_CDH(\"CS101\", \"W\", \"9AM\");\n");
//    insert_CDH("CS101", "W", "9AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("insert_CDH(\"CS101\", \"F\", \"9AM\");\n");
//    insert_CDH("CS101", "F", "9AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("insert_CDH(\"EE200\", \"Tu\", \"10AM\");\n");
//    insert_CDH("EE200", "Tu", "10AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("insert_CDH(\"EE200\", \"W\", \"1PM\");\n");
//    insert_CDH("EE200", "W", "1PM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("insert_CDH(\"EE200\", \"Th\", \"10AM\");\n");
//    insert_CDH("EE200", "Th", "10AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("insert_CDH(\"EE200\", \"Th\", \"10AM\");\n");
//    insert_CDH("EE200", "Th", "10AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("delete_CDH(\"EE200\", \"Tu\", \"10AM\");\n");
//    delete_CDH("EE200", "Tu", "10AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("delete_CDH(\"EE200\", \"*\", \"*\");\n");
//    delete_CDH("EE200", "*", "*");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("delete_CDH(\"AB123\", \"*\", \"*\");\n");
//    delete_CDH("AB123", "*", "*");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("lookup_CDH(\"CS101\", \"M\", \"9AM\");\n");
//    lookup_CDH("CS101", "M", "9AM");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("lookup_CDH(\"CS101\", \"*\", \"*\");\n");
//    lookup_CDH("CS101", "*", "*");
//    print_relation_CDH();
//    printf("\n");
//
//    printf("lookup_CDH(\"AB123\", \"*\", \"*\");\n");
//    lookup_CDH("AB123", "*", "*");
//    print_relation_CDH();
//    printf("\n");
    

    
//    /*--------------------Course-StudentId-Grade Demonstration--------------------*/
//    printf("Course-StudentId-Grade Demonstration\n");
//
//    new_HashArray_CSG();
//    printf("\n");
//
//    printf("insert_CSG(\"CS101\", 12345, \"A\");\n");
//    insert_CSG("CS101", 12345, "A");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("insert_CSG(\"CS101\", 67890, \"B\");\n");
//    insert_CSG("CS101", 67890, "B");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("insert_CSG(\"EE200\", 12345, \"C\");\n");
//    insert_CSG("EE200", 12345, "C");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("insert_CSG(\"EE200\", 22222, \"B+\");\n");
//    insert_CSG("EE200", 22222, "B+");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("insert_CSG(\"CS101\", 33333, \"A-\");\n");
//    insert_CSG("CS101", 33333, "A-");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("insert_CSG(\"Ph100\", 67890, \"C+\");\n");
//    insert_CSG("PH100", 67890, "C+");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("insert_CSG(\"Ph100\", 67890, \"C+\");\n");
//    insert_CSG("PH100", 67890, "C+");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("delete_CSG(\"CS101\", 33333, \"A-\");\n");
//    delete_CSG("CS101", 33333, "A-");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("delete_CSG(\"CS101\", 33333, \"A-\");\n");
//    delete_CSG("CS101", 33333, "A-");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("delete_CSG(\"*\", 12345, \"*\");\n");
//    delete_CSG("*", 12345, "*");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("lookup_CSG(\"Ph100\", 67890, \"C+\");\n");
//    lookup_CSG("PH100", 67890, "C+");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("lookup_CSG(\"*\", 67890, \"*\");\n");
//    lookup_CSG("*", 67890, "*");
//    print_relation_CSG();
//    printf("\n");
//
//    printf("lookup_CSG(\"CS101\", 33333, \"A-\");\n");
//    lookup_CSG("CS101", 33333, "A-");
//    print_relation_CSG();
//    printf("\n");
//
    
    
    
    
    
}
