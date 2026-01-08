#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Mevcut Fonksiyonlar
void displayHeader(const string& title);
void displayError(const string& message);
void displayMenu();

// EKSİK OLAN ZAMAN FONKSİYONLARI (Bunları ekle):
int timeToMinutes(const string& timeStr);
string minutesToTime(int totalMinutes);
string addMinutesToTime(const string& timeStr, int minutesToAdd);