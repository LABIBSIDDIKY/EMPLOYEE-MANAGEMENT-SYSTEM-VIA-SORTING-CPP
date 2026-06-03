#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ---------------- Employee Structure ----------------
struct Employee {
    string empID;
    string empName;
    string phoneNum;
    int numberOfYearsWorked;
    double baseSalary;
    double incrementPercent;
    double totalSalary;
};
// ---------------- Functions ----------------
double calcTotalSalary(double base, double incPercent, int years) {
    return base + (base * incPercent / 100 * years);
}
void showEmployee(Employee e) {
    cout << "ID: " << e.empID
         << " | Name: " << e.empName
         << " | Phone: " << e.phoneNum
         << " | Years Worked: " << e.numberOfYearsWorked
         << " | Base Salary: " << e.baseSalary
         << " | Increment %: " << e.incrementPercent
         << " | Total Salary: " << e.totalSalary << endl;
}
// for searching regardless of case
bool ciMatch(string a, string b) {
    if(a.size() != b.size()) return false;
    for(size_t i = 0; i < a.size(); i++)
        if(tolower(a[i]) != tolower(b[i])) return false;
    return true;
}
// search by id, name, or phone
int findEmployee(vector<Employee> &list, string key, string type) {
    for(size_t i=0; i<list.size(); i++) {
        if(type=="id" && list[i].empID==key) return i;
        if(type=="name" && ciMatch(list[i].empName,key)) return i;
        if(type=="phone" && list[i].phoneNum==key) return i;
    }
    return -1;
}
// ----------------  Name Sort Alphabetically  ----------------
void sortByName(vector<Employee> &list) {
    for(size_t i=0; i<list.size()-1; i++) {
        for(size_t j=i+1; j<list.size(); j++) {
            if(list[i].empName > list[j].empName)
                swap(list[i], list[j]);
        }
    }
}
// ----------------  Selection Sort by ID Ascending ----------------
void sortByID(vector<Employee> &list) {
    int n = list.size();
    for(int i=0;i<n-1;i++) {
        int minIndex = i;
        for(int j=i+1;j<n;j++) {
            if(list[j].empID < list[minIndex].empID)
                minIndex = j;
        }
        if(minIndex != i)
            swap(list[i], list[minIndex]);
    }
}
// ---------------- Merge Sort by Salary Descending (using vector) ----------------
void mergeSalary(vector<Employee> &list, int left, int mid, int right) {
    vector<Employee> L(list.begin() + left, list.begin() + mid + 1);
    vector<Employee> R(list.begin() + mid + 1, list.begin() + right + 1);
    int i=0, j=0, k=left;
    while(i<L.size() && j<R.size()) {
        if(L[i].totalSalary >= R[j].totalSalary) list[k++] = L[i++];
        else list[k++] = R[j++];
    }
    while(i<L.size()) list[k++] = L[i++];
    while(j<R.size()) list[k++] = R[j++];
}
void mergeSortSalary(vector<Employee> &list, int left, int right) {
    if(left<right) {
        int mid = (left+right)/2;
        mergeSortSalary(list,left,mid);
        mergeSortSalary(list,mid+1,right);
        mergeSalary(list,left,mid,right);
    }
}
// ---------------- Display All Employees ----------------
void showAll(vector<Employee> list) {
    if(list.empty()) {
        cout << "No employees.\n";
        return;
    }
    // Sort by name
    vector<Employee> nameList = list;
    sortByName(nameList);
    cout << "\n-- Employees Alphabetically by Name --\n";
    for(auto e: nameList) showEmployee(e);
    // Sort by ID
    vector<Employee> idList = list;
    sortByID(idList);
    cout << "\n-- Employees by ID Ascending --\n";
    for(auto e: idList) showEmployee(e);
// Sort by salary descending
    vector<Employee> salaryList = list;
    mergeSortSalary(salaryList,0,salaryList.size()-1);
    cout << "\n-- Employees by Total Salary Descending --\n";
    for(auto e: salaryList) showEmployee(e);
}
// ---------------- Main ----------------
int main() {
    vector<Employee> employeeList;
    int choice;
    do {
        cout << "\n1.Add Employee \n2.Remove Last \n3.Search Name \n4.Search Phone \n5.Search ID \n6.Delete \n7.Show All \n8.Exit\n";
        cout << "Choice: "; cin >> choice; cin.ignore();
        if(choice==1) {
            Employee e;
            cout << "ID: "; getline(cin,e.empID);
            cout << "Name: "; getline(cin,e.empName);
            cout << "Phone: "; getline(cin,e.phoneNum);
            cout << "Number of Years Worked: "; cin >> e.numberOfYearsWorked;
            cout << "Base Salary: "; cin >> e.baseSalary;
            cout << "Increment %: "; cin >> e.incrementPercent; cin.ignore();
            e.totalSalary = calcTotalSalary(e.baseSalary,e.incrementPercent,e.numberOfYearsWorked);
            employeeList.push_back(e);
            cout << "Employee added.\n";
        }
        else if(choice==2) {
            if(!employeeList.empty()) {
                cout << "Removed:\n"; showEmployee(employeeList.back());
                employeeList.pop_back();
            } else cout << "Employee list is empty.\n";
        }
        else if(choice==3) {
            string key; cout << "Name: "; getline(cin,key);
            int i = findEmployee(employeeList,key,"name");
            if(i!=-1) showEmployee(employeeList[i]);
            else cout << "Not found.\n";
        }
        else if(choice==4) {
            string key; cout << "Phone: "; getline(cin,key);
            int i = findEmployee(employeeList,key,"phone");
            if(i!=-1) showEmployee(employeeList[i]);
            else cout << "Not found.\n";
        }
        else if(choice==5) {
            string key; cout << "ID: "; getline(cin,key);
            int i = findEmployee(employeeList,key,"id");
            if(i!=-1) showEmployee(employeeList[i]);
            else cout << "Not found.\n";
        }
        else if(choice==6) {
            int t; cout << "Delete by: 1.Name 2.Phone 3.ID: "; cin >> t; cin.ignore();
            string key;
            if(t==1){ cout<<"Name: "; getline(cin,key);}
            else if(t==2){ cout<<"Phone: "; getline(cin,key);}
            else if(t==3){ cout<<"ID: "; getline(cin,key);}
            else { cout<<"Invalid\n"; continue; }
            string type = (t==1?"name":(t==2?"phone":"id"));
            int i = findEmployee(employeeList,key,type);
            if(i!=-1) { cout<<"Deleted:\n"; showEmployee(employeeList[i]); employeeList.erase(employeeList.begin()+i);}
            else cout<<"Not found.\n";
        }
        else if(choice==7) showAll(employeeList);
        else if(choice==8) cout<<"Bye!\n";
        else cout<<"Invalid choice!\n";

    } while(choice!=8);
    return 0;
}
