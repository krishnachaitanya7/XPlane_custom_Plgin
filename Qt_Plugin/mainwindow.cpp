#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <iostream>
#include <QMessageBox>
#include <regex>
#include <fstream>
#include <experimental/filesystem>



// Const Declarations
const int no_of_questions {2};
const int no_options_each_question {4};
const int no_radio_buttons {no_of_questions*no_options_each_question};
static std::map<int, int> questionnaire_answers;
static std::ofstream myfile;
static std::string save_to_file;
const std::string filename {"example.csv"};
// End Declarations
// Function Declarations

//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void add_options(std::string my_option){
    // The regex for extracting the number is :
    // Debugging: https://regex101.com/r/2zfr41/1/

    std::regex re(".*_([0-9]*)");
    std::smatch match;
    if (regex_search(my_option, match, re) == true) {
        int my_number = std::stoi(match.str(1));
        int question_number = my_number/10;
        int option_choosen = my_number % 10;
//        std::cout << "Question Number: " << question_number << " Option choosen is: " << option_choosen <<  std::endl;
        questionnaire_answers.insert(std::make_pair(question_number, option_choosen));
        std::string append_string = std::to_string(option_choosen);
        append_string.append(", ");
        save_to_file.append(append_string);
    }

}

bool are_all_questions_checked(){
    if(questionnaire_answers.size() == no_of_questions){
        return true;
    } else{
        return false;
    }

}

void MainWindow::on_buttonBox_accepted()
{
    bool exist = std::experimental::filesystem::exists(filename);
    if (exist){
        std::string csv_firststring = "ID, my_first_question, my_second_question \n";
        myfile << csv_firststring;

    }
    myfile.open("example.csv", std::ios_base::app);

    int radio_buttons_iterator {0};
    for(int j=1; j<=no_of_questions; ++j){
        for(int i=1; i<=no_options_each_question; ++i){
            QString my_radio_button_string = "radioButton_" + QString::number(j) + QString::number(i);
            if(MainWindow::findChild<QRadioButton *>(my_radio_button_string)->isChecked()){
//                std::cout << "The checked Button is: "<< my_radio_button_string.toUtf8().constData() << std::endl;
                add_options(my_radio_button_string.toUtf8().constData());
            }
            ++radio_buttons_iterator;
        }
    }
    if(are_all_questions_checked()){
        myfile << "1, ";
        myfile << save_to_file;
        this->close();
    } else{
        QMessageBox msgBox;
        msgBox.setText("You haven't filled up all your questions. Please fill all of them. "
                       "Press ok to go back and fill the rest of the questions");
        msgBox.exec();

    }



}
void MainWindow::on_buttonBox_rejected(){
    this->close();
}


