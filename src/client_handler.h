#include "include/cef_client.h"

class ClientHandler : public CefClient,
                      public CefDisplayHandler,
                      public CefLifeSpanHandler,
                      public CefLoadHandler
{
public:
    ClientHandler();
    ~ClientHandler();

    // Provide access to the single global instance of this object.
    static ClientHandler* GetInstance();

    // CefClient methods:
    virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override {
        return this;
    }
    virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override {
        return this;
    }
    virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override {
        return this;
    }

    // CefLifeSpanHandler
    virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

private:
    // Include the default reference counting implementation.
    IMPLEMENT_REFCOUNTING(ClientHandler);
};
