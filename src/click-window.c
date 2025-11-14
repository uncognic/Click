/* MIT License
 *
 * Copyright (c) 2025 Ilyas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 */

#include "config.h"

#include "click-window.h"

struct _ClickWindow
{
	AdwApplicationWindow  parent_instance;

	/* Template widgets */
	GtkLabel            *label;
        GtkToggleButton     *button;
};

G_DEFINE_FINAL_TYPE (ClickWindow, click_window, ADW_TYPE_APPLICATION_WINDOW)

static void
on_button_clicked(GtkButton *button, ClickWindow *self)
{
  if (gtk_toggle_button_get_active(self->button)) {
        gtk_label_set_text(self->label, "Locked");
        gtk_button_set_label(GTK_BUTTON(self->button), "Unlock");
    } else {
        gtk_label_set_text(self->label, "Unlocked");
        gtk_button_set_label(GTK_BUTTON(self->button), "Lock");
    }
}

static void
click_window_class_init (ClickWindowClass *klass)
{
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

    gtk_widget_class_set_template_from_resource (widget_class, "/dev/uncognic/Click/click-window.ui");
    gtk_widget_class_bind_template_child(widget_class, ClickWindow, label);
    gtk_widget_class_bind_template_child(widget_class, ClickWindow, button);
}

static void
click_window_init (ClickWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  g_signal_connect(self->button, "clicked", G_CALLBACK(on_button_clicked), self);
  gtk_label_set_text(self->label, "Unlocked");
    gtk_button_set_label(GTK_BUTTON(self->button), "Lock");
    gtk_toggle_button_set_active(self->button, FALSE);

}
