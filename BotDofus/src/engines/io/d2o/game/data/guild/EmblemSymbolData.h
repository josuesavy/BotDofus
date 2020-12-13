#ifndef EMBLEMSYMBOLDATA_H
#define EMBLEMSYMBOLDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class EmblemSymbolData : public AbstractGameData
{
public:
  int getId() const;
  int getIconId() const;
  int getSkinId() const;
  int getOrder() const;
  int getCategoryId() const;
  bool getColorizable() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_iconId;
  int m_skinId;
  int m_order;
  int m_categoryId;
  bool m_colorizable;
};

#endif // EMBLEMSYMBOLDATA_H