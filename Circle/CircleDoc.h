
// CircleDoc.h : интерфейс класса CCircleDoc
//


#pragma once


class CCircleDoc : public CDocument
{
protected: // создать только из сериализации
	CCircleDoc();
	DECLARE_DYNCREATE(CCircleDoc)

// Атрибуты
public:
	int m_PosX; // координата x (по горизонтали) центра круга
	int m_PosY; // координата y (по вертикали) центра круга
	CString m_strText; // для хранения текста
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CCircleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
