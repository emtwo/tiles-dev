/* -*- Mode: C++; tab-width: 40; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsICanvasRenderingContextInternal_h___
#define nsICanvasRenderingContextInternal_h___

#include "nsISupports.h"
#include "nsIInputStream.h"
#include "nsIDocShell.h"
#include "mozilla/dom/HTMLCanvasElement.h"
#include "GraphicsFilter.h"
#include "mozilla/RefPtr.h"

#define NS_ICANVASRENDERINGCONTEXTINTERNAL_IID \
{ 0x9a6a5bdf, 0x1261, 0x4057, \
  { 0x85, 0xcc, 0xaf, 0x97, 0x6c, 0x36, 0x99, 0xa9 } }

class gfxContext;
class gfxASurface;
class nsDisplayListBuilder;

namespace mozilla {
namespace layers {
class CanvasLayer;
class LayerManager;
}
namespace ipc {
class Shmem;
}
namespace gfx {
class SourceSurface;
}
}

class nsICanvasRenderingContextInternal : public nsISupports {
public:
  typedef mozilla::layers::CanvasLayer CanvasLayer;
  typedef mozilla::layers::LayerManager LayerManager;

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICANVASRENDERINGCONTEXTINTERNAL_IID)

  enum {
    RenderFlagPremultAlpha = 0x1
  };

  void SetCanvasElement(mozilla::dom::HTMLCanvasElement* aParentCanvas)
  {
    mCanvasElement = aParentCanvas;
  }
  mozilla::dom::HTMLCanvasElement* GetParentObject() const
  {
    return mCanvasElement;
  }

#ifdef DEBUG
    // Useful for testing
    virtual int32_t GetWidth() const = 0;
    virtual int32_t GetHeight() const = 0;
#endif

  // Sets the dimensions of the canvas, in pixels.  Called
  // whenever the size of the element changes.
  NS_IMETHOD SetDimensions(int32_t width, int32_t height) = 0;

  NS_IMETHOD InitializeWithSurface(nsIDocShell *docShell, gfxASurface *surface, int32_t width, int32_t height) = 0;

  // Render the canvas at the origin of the given gfxContext
  NS_IMETHOD Render(gfxContext *ctx,
                    GraphicsFilter aFilter,
                    uint32_t aFlags = RenderFlagPremultAlpha) = 0;

  // Creates an image buffer. Returns null on failure.
  virtual void GetImageBuffer(uint8_t** aImageBuffer, int32_t* aFormat) = 0;

  // Gives you a stream containing the image represented by this context.
  // The format is given in aMimeTime, for example "image/png".
  //
  // If the image format does not support transparency or aIncludeTransparency
  // is false, alpha will be discarded and the result will be the image
  // composited on black.
  NS_IMETHOD GetInputStream(const char *aMimeType,
                            const char16_t *aEncoderOptions,
                            nsIInputStream **aStream) = 0;

  // If this canvas context can be represented with a simple Thebes surface,
  // return the surface.  Otherwise returns an error.
  NS_IMETHOD GetThebesSurface(gfxASurface **surface) = 0;
  
  // This gets an Azure SourceSurface for the canvas, this will be a snapshot
  // of the canvas at the time it was called.
  virtual mozilla::TemporaryRef<mozilla::gfx::SourceSurface> GetSurfaceSnapshot() = 0;

  // If this context is opaque, the backing store of the canvas should
  // be created as opaque; all compositing operators should assume the
  // dst alpha is always 1.0.  If this is never called, the context
  // defaults to false (not opaque).
  NS_IMETHOD SetIsOpaque(bool isOpaque) = 0;
  virtual bool GetIsOpaque() = 0;

  // Invalidate this context and release any held resources, in preperation
  // for possibly reinitializing with SetDimensions/InitializeWithSurface.
  NS_IMETHOD Reset() = 0;

  // Return the CanvasLayer for this context, creating
  // one for the given layer manager if not available.
  virtual already_AddRefed<CanvasLayer> GetCanvasLayer(nsDisplayListBuilder* aBuilder,
                                                       CanvasLayer *aOldLayer,
                                                       LayerManager *aManager) = 0;

  // Return true if the canvas should be forced to be "inactive" to ensure
  // it can be drawn to the screen even if it's too large to be blitted by
  // an accelerated CanvasLayer.
  virtual bool ShouldForceInactiveLayer(LayerManager *aManager) { return false; }

  virtual void MarkContextClean() = 0;

  // Redraw the dirty rectangle of this canvas.
  NS_IMETHOD Redraw(const gfxRect &dirty) = 0;

  NS_IMETHOD SetContextOptions(JSContext* aCx, JS::Handle<JS::Value> aOptions) { return NS_OK; }

  //
  // shmem support
  //

  // If this context can be set to use Mozilla's Shmem segments as its backing
  // store, this will set it to that state. Note that if you have drawn
  // anything into this canvas before changing the shmem state, it will be
  // lost.
  NS_IMETHOD SetIsIPC(bool isIPC) = 0;

protected:
  nsRefPtr<mozilla::dom::HTMLCanvasElement> mCanvasElement;
};

namespace mozilla {
namespace dom {

}
}

NS_DEFINE_STATIC_IID_ACCESSOR(nsICanvasRenderingContextInternal,
                              NS_ICANVASRENDERINGCONTEXTINTERNAL_IID)

#endif /* nsICanvasRenderingContextInternal_h___ */
