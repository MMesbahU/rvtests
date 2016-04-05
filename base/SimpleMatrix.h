#ifndef _SIMPLEMATRIX_H_
#define _SIMPLEMATRIX_H_

#include <vector>
#include <set>
#include <string>
#include <stdio.h>

/**
 * This matrix class is for convenient store matrix class.
 *
 * Row (column) names are by default r1, r2, ... (c1, c2, ...),
 * and they automatically grow/shrink with data, unless specified otherwise
 */
class SimpleMatrix {
 public:
  SimpleMatrix(){};
  SimpleMatrix(int nr, int nc) { this->resize(nr, nc); }
  int readFile(const char* f);
  int writeFile(const char* f);
  std::vector<double>& operator[](int i) { return mat[i]; }
  const std::vector<double>& operator[](int i) const { return mat[i]; }
  void resize(int nrow, int ncol);
  template <typename T>
  int appendRow(const std::vector<T>& d, const std::string& label = "");
  template <typename T>
  int appendCol(const std::vector<T>& d, const std::string& label = "");
  int deleteRow(int i);
  int deleteCol(int i);
  void clear() {
    mat.clear();
    rowName.clear();
    colName.clear();
  }
  void zero() {
    for (unsigned int i = 0; i < mat.size(); i++) {
      for (unsigned int j = 0; j < mat[i].size(); j++) {
        mat[i][j] = 0.0;
      }
    }
  }
  int nrow() const { return mat.size(); };
  int ncol() const {
    if (mat.size() == 0) return 0;
    return mat[0].size();
  }
  const std::vector<std::string>& getRowName() const { return this->rowName; };
  const std::vector<std::string>& getColName() const { return this->colName; };
  int setRowName(const int idx, const std::string& s);
  int setColName(const int idx, const std::string& s);
  int setRowName(const std::vector<std::string>& name);
  int setColName(const std::vector<std::string>& name);

  /**
   * Remove rows in which their row names are in @param rowNamSet
   */
  int dropRow(const std::set<std::string>& rowNameSet);
  int dropRow(const std::vector<int>& index);

  /**
   * Assign row @param from to row @param to
   */
  int assignRow(const int to, const int from);

  void extractCol(int col, std::vector<double>* v) const;
  std::vector<double> extractCol(int col) const;
  int setCol(int col, const std::vector<double>& v);

  std::vector<int> allMissingRows() const;
 private:
  void resetRowName();
  void resetColName();

 private:
  std::vector<std::string> rowName;
  std::vector<std::string> colName;
  std::vector<std::vector<double> > mat;
};

#endif /* _SIMPLEMATRIX_H_ */
