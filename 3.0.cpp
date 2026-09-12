#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <map>
#include <vector>

int readIntFromLine(const std::string& prompt)
{
    using namespace std;
    string line;
    int value;
    for (;;)
    {
        cout << prompt << flush;
        if (!getline(cin, line))
        {
            cin.clear();
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }
        stringstream ss(line);
        if (ss >> value)
        {
            string rest;
            if (!(ss >> rest))
                return value;
        }

        cout << "输入无效，请输入一个整数。" << endl;
    }
}

// Function to get the language choice from the user
std::string chooseLanguage() {
    using namespace std;
    map<string, string> languages = {
        {"1", "中文"},
        {"2", "English"},
        {"3", "日本語"},
        {"4", "Français"},
        {"5", "Deutsch"},
        {"6", "Español"},
        {"7", "العربية"}
    };

    cout << "请选择语言:" << endl;
    cout << "1) 中文" << endl;
    cout << "2) English" << endl;
    cout << "3) 日本語" << endl;
    cout << "4) Français" << endl;
    cout << "5) Deutsch" << endl;
    cout << "6) Español" << endl;
    cout << "7) العربية" << endl;

    string langChoice;
    while (true) {
        cout << "输入选项编号并回车: " << flush;
        if (!getline(cin, langChoice)) {
            cin.clear();
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }
        if (languages.find(langChoice) != languages.end()) {
            return languages[langChoice];
        } else {
            cout << "无效选项，请重试。" << endl;
        }
    }
}

int main(void)
{
    using namespace std;

    string language = chooseLanguage();

    map<string, vector<string>> menuOptions = {
        {"中文", {"请选择功能：", "1) hakimi 加法小程序", "2) hakimi学你说话", "3) 退出 (或 输入 q)", "4) 返回上一步", "输入选项编号并回车："}},
        {"English", {"Please select a function:", "1) hakimi addition program", "2) hakimi repeats what you say", "3) Exit (or type q)", "4) Go back to the previous step", "Enter the option number and press Enter:"}},
        {"日本語", {"機能を選択してください：", "1) hakimi 加算プログラム", "2) hakimiがあなたの言葉を繰り返します", "3) 終了 (または q を入力)", "4) 前のステップに戻る", "オプション番号を入力してEnterキーを押してください："}},
        {"Français", {"Veuillez sélectionner une fonction :", "1) Programme d'addition hakimi", "2) hakimi répète ce que vous dites", "3) Quitter (ou tapez q)", "4) Revenir à l'étape précédente", "Entrez le numéro de l'option et appuyez sur Entrée :"}},
        {"Deutsch", {"Bitte wählen Sie eine Funktion:", "1) hakimi Additionsprogramm", "2) hakimi wiederholt, was Sie sagen", "3) Beenden (oder geben Sie q ein)", "4) Zum vorherigen Schritt zurückkehren", "Geben Sie die Optionsnummer ein und drücken Sie die Eingabetaste:"}},
        {"Español", {"Por favor seleccione una función:", "1) Programa de suma de hakimi", "2) hakimi repite lo que dices", "3) Salir (o escriba q)", "4) Volver al paso anterior", "Ingrese el número de opción y presione Enter:"}},
        {"العربية", {"يرجى اختيار وظيفة:", "1) برنامج جمع hakimi", "2) hakimi يكرر ما تقوله", "3) خروج (أو اكتب q)", "4) العودة إلى الخطوة السابقة", "أدخل رقم الخيار واضغط Enter:"}}
    };

    vector<string> previousChoices;

    for (;;) {
        cout << "======================" << endl;
        cout << menuOptions[language][0] << endl;
        cout << menuOptions[language][1] << endl;
        cout << menuOptions[language][2] << endl;
        cout << menuOptions[language][3] << endl;
        cout << menuOptions[language][4] << endl;
        cout << "by 卢本伟" << endl;
        cout << "qq 3178644407" << endl;

        string choice;
        if (!getline(cin, choice)) {
            cin.clear();
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }
        auto trim = [](string& s) {
            size_t a = s.find_first_not_of(" \t\r\n");
            size_t b = s.find_last_not_of(" \t\r\n");
            if (a == string::npos) { s.clear(); return; }
            s = s.substr(a, b - a + 1);
        };
        trim(choice);

        if (choice == "1") {
            previousChoices.push_back("1");
            int hakimi = readIntFromLine(language == "中文" ? "告诉我你有多少个hakimi? " :
                language == "English" ? "Tell me how many hakimi do you have? " :
                language == "日本語" ? "あなたは何個のhakimiを持っていますか？ " :
                language == "Français" ? "Combien de hakimi avez-vous ? " :
                language == "Deutsch" ? "Wie viele hakimi haben Sie? " :
                language == "Español" ? "¿Cuántos hakimi tienes? " :
                "كم عدد hakimi لديك؟ ");
            cout << (language == "中文" ? "现在你太有hakimi了 我给你114514个" :
                language == "English" ? "Now you have too many hakimi, I give you 114514 more" :
                language == "日本語" ? "今、あなたはたくさんのhakimiを持っています。114514個をあげます。" :
                language == "Français" ? "Maintenant, vous avez trop de hakimi, je vous en donne 114514 de plus." :
                language == "Deutsch" ? "Jetzt haben Sie zu viele hakimi, ich gebe Ihnen 114514 mehr." :
                language == "Español" ? "Ahora tienes demasiados hakimi, te doy 114514 más." :
                "الآن لديك الكثير من hakimi، سأعطيك 114514 أخرى.") << endl;
            hakimi = 114514 + hakimi;
            cout << (language == "中文" ? "所以你有" :
                language == "English" ? "So now you have " :
                language == "日本語" ? "だから今、あなたは " :
                language == "Français" ? "Donc maintenant, vous avez " :
                language == "Deutsch" ? "Also haben Sie jetzt " :
                language == "Español" ? "Así que ahora tienes " :
                "لذا الآن لديك ") << hakimi << (language == "中文" ? "个hakimi了" :
                    language == "English" ? " hakimi" :
                    language == "日本語" ? " 個のhakimiを持っています。" :
                    language == "Français" ? " hakimi." :
                    language == "Deutsch" ? " hakimi." :
                    language == "Español" ? " hakimi." :
                    " hakimi.") << endl;
            cout << (language == "中文" ? "智障hakimi小程序 by卢本伟 去吧小子" :
                language == "English" ? "Stupid hakimi program by Lu Benwei, go ahead kid" :
                language == "日本語" ? "馬鹿なhakimiプログラム by ルーベンウェイ 行け少年" :
                language == "Français" ? "Programme stupide de hakimi par Lu Benwei, vas-y gamin" :
                language == "Deutsch" ? "Dummes hakimi-Programm von Lu Benwei, los geht's, Junge" :
                language == "Español" ? "Programa estúpido de hakimi por Lu Benwei, adelante chico" :
                "برنامج hakimi الغبي بواسطة لو بن وي، انطلق يا صغير") << endl;
            cout << (language == "中文" ? "按回车返回主菜单..." :
                language == "English" ? "Press Enter to return to the main menu..." :
                language == "日本語" ? "Enterキーを押してメインメニューに戻ります..." :
                language == "Français" ? "Appuyez sur Entrée pour revenir au menu principal..." :
                language == "Deutsch" ? "Drücken Sie die Eingabetaste, um zum Hauptmenü zurückzukehren..." :
                language == "Español" ? "Presiona Enter para regresar al menú principal..." :
                "اضغط Enter للعودة إلى القائمة الرئيسية...") << endl;
            string tmp;
            getline(cin, tmp);
        }
        else if (choice == "2") {
            previousChoices.push_back("2");
            cout << (language == "中文" ? "我学你说话（输入内容将被回显）。输入 \":q\" 或 \"exit\" 或单独的 \"q\" 返回主菜单。" :
                language == "English" ? "I will repeat what you say. Type \":q\", \"exit\" or \"q\" to return to the main menu." :
                language == "日本語" ? "私はあなたの言葉を繰り返します。\":q\"、\"exit\"、または\"q\"を入力してメインメニューに戻ります。" :
                language == "Français" ? "Je vais répéter ce que vous dites. Tapez \":q\", \"exit\" ou \"q\" pour revenir au menu principal." :
                language == "Deutsch" ? "Ich werde wiederholen, was Sie sagen. Geben Sie \":q\", \"exit\" oder \"q\" ein, um zum Hauptmenü zurückzukehren." :
                language == "Español" ? "Repetiré lo que digas. Escribe \":q\", \"exit\" o \"q\" para regresar al menú principal." :
                "سأكرر ما تقوله. اكتب \":q\" أو \"exit\" أو \"q\" للعودة إلى القائمة الرئيسية.") << endl;
            for (;;) {
                cout << "> " << flush;
                string line;
                if (!getline(cin, line)) {
                    cin.clear();
                    this_thread::sleep_for(chrono::milliseconds(100));
                    continue;
                }

                string t = line;
                trim(t);
                if (t == ":q" || t == "exit" || t == "q" || t == "Q") {
                    cout << (language == "中文" ? "返回主菜单..." :
                        language == "English" ? "Returning to the main menu..." :
                        language == "日本語" ? "メインメニューに戻ります..." :
                        language == "Français" ? "Retour au menu principal..." :
                        language == "Deutsch" ? "Zurück zum Hauptmenü..." :
                        language == "Español" ? "Regresando al menú principal..." :
                        "العودة إلى القائمة الرئيسية...") << endl;
                    break;
                }

                cout << line << endl;
            }
        }
        else if (choice == "3" || choice == "q" || choice == "Q") {
            cout << (language == "中文" ? "退出程序..." :
                language == "English" ? "Exiting the program..." :
                language == "日本語" ? "プログラムを終了します..." :
                language == "Français" ? "Quitter le programme..." :
                language == "Deutsch" ? "Programm wird beendet..." :
                language == "Español" ? "Saliendo del programa..." :
                "جارٍ إنهاء البرنامج...") << endl;
            break;
        }
        else if (choice == "4") {
            if (!previousChoices.empty()) {
                string lastChoice = previousChoices.back();
                previousChoices.pop_back();
                cout << (language == "中文" ? "返回上一步..." :
                    language == "English" ? "Going back to the previous step..." :
                    language == "日本語" ? "前のステップに戻ります..." :
                    language == "Français" ? "Retour à l'étape précédente..." :
                    language == "Deutsch" ? "Zurück zum vorherigen Schritt..." :
                    language == "Español" ? "Volviendo al paso anterior..." :
                    "العودة إلى الخطوة السابقة...") << endl;
                choice = lastChoice; // Set choice to the last choice
                continue; // Restart the loop with the previous choice
            } else {
                cout << (language == "中文" ? "没有上一步可以返回。" :
                    language == "English" ? "No previous step to go back to." :
                    language == "日本語" ? "戻るステップがありません。" :
                    language == "Français" ? "Aucune étape précédente à laquelle revenir." :
                    language == "Deutsch" ? "Kein vorheriger Schritt, zu dem zurückgekehrt werden kann." :
                    language == "Español" ? "No hay un paso anterior al que volver." :
                    "لا توجد خطوة سابقة للعودة إليها.") << endl;
            }
        }
        else {
            cout << (language == "中文" ? "无效选项，请重试。" :
                language == "English" ? "Invalid option, please try again." :
                language == "日本語" ? "無効なオプションです。もう一度お試しください。" :
                language == "Français" ? "Option invalide, veuillez réessayer." :
                language == "Deutsch" ? "Ungültige Option, bitte versuchen Sie es erneut." :
                language == "Español" ? "Opción no válida, inténtalo de nuevo." :
                "خيار غير صالح، حاول مرة أخرى.") << endl;
        }
    }

    return 114514;
}