#include "atsarquiz.h"
#include "ui_atsarquiz.h"
#include "atsar-rust-lib/src/rust_questions_api.h"
#include <iostream>
#include <memory>
#include <string>
#include <numeric>

class Question {
public:
    virtual ~Question() = default;
    std::string question_text;
};
class MultipleChoiceQuestion : public Question {
public:
    std::vector<std::string> options;
    size_t correct_answer_index;

    MultipleChoiceQuestion(size_t index) {
        std::unique_ptr<char, CStringDeleter> text_ptr(get_question_text(index));
        question_text = (text_ptr !=nullptr) ? text_ptr.get() : "(error getting text)";

        size_t mc_options_counts=0;
        char **mc_options_raw = get_mc_options(index, &mc_options_counts);

        if (mc_options_raw != nullptr && mc_options_counts>0) {
            options.reserve(mc_options_counts);
            for (size_t j=0; j<mc_options_counts; ++j) {
                options.emplace_back(mc_options_raw[j]);
            }
            FreeRustStringArray(mc_options_raw,mc_options_counts);
        }
        correct_answer_index =get_mc_correct_answer(index)
    }
};


void FreeRustStringArray(char **array_ptr, size_t count) {
    if (array_ptr != nullptr) {
        free_string_array(array_ptr, count);
    }
}

void FreeRustBoolArray(unsigned char *array_ptr) {
    if (array_ptr != nullptr) {
        free_bool_array(array_ptr);
    }
}

struct CStringDeleter {
    void operator()(char *s) const {
        if (s != nullptr) {
            free_cstring(s);
        }
    }
};

atsarquiz::atsarquiz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::atsarquiz)
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file", "YAML Files (*.yaml *.yml);;All Files (*)");
    if (!fileName.isEmpty())
    {
        QByteArray byteArray = fileName.toUtf8();
        const char* filepath = byteArray.constData();
        if (load_questions_into_memory(filepath) != 0)
        QMessageBox::warning(this,"Failed","Failed to load the questions");
    }
    ui->setupUi(this);
    int currentQuestion = 1;
    size_t totalQuestions = get_total_question_count();
    update_Quiz_progression(currentQuestion,totalQuestions);
}

atsarquiz::~atsarquiz()
{
    delete ui;
}

void atsarquiz::on_Quit_triggered()
{
    this->close();
}

void atsarquiz::update_Quiz_progression(int currentQuestion, size_t totalQuestions)
{
    QString progressionText = QString("%1/%2").arg(currentQuestion).arg(totalQuestions);
    ui->Progress->setText(progressionText);
}

