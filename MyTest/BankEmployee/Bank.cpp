#include <iostream>
#include <string>
#include "Customer.h"
#include "Account.h"
#include "BankEmployee.h"
#include "Administrator.h"
#include "Transaction.h"
#include "LoanApplication.h"


// 主函数
int main() {
    // 创建客户对象
    Customer customer1("张三", "123456789", "北京", "13800000000");

    // 创建账户对象
    Account account1("ACC1001", customer1);
    account1.deposit(1000);

    // 创建银行职员对象
    BankEmployee employee1("EMP001", "李四");

    // 创建管理员对象
    Administrator admin1("ADMIN001", "王五");

    // 创建交易记录对象
    Transaction transaction1("TRANS001", account1.getAccountNumber(), 500, "2023-10-01", "取款");

    // 创建贷款申请对象
    LoanApplication loan1("LOAN001", customer1, 50000);

    // 演示功能
    std::cout << "客户信息: " << customer1.getInfo() << std::endl;
    std::cout << "账户余额: " << account1.getBalance() << std::endl;
    employee1.viewCustomerInfo(customer1);
    admin1.addUser(customer1);
    transaction1.displayTransaction();
    loan1.approve();
    std::cout << "贷款申请状态: " << loan1.getStatus() << std::endl;

    return 0;
}
